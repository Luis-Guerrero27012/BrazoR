#include <WiFi.h>
#include <WebServer.h>  // Librería para servidor web
#include <ESPmDNS.h>     // Librería para mDNS

// Definimos los pines para conectar los controladores A4988 de los tres motores
#define DIR_PIN_1 33
#define STEP_PIN_1 25
#define DIR_PIN_2 12
#define STEP_PIN_2 14
#define DIR_PIN_3 26
#define STEP_PIN_3 27
#define RELAY_PIN 13  // Pin para el relé

// Definimos el número de pasos por revolución (esto varía según el motor)
#define STEPS_PER_REV 500

// Credenciales de WiFi
const char* ssid = "Santy";       // Reemplaza con el nombre de tu red WiFi
const char* password = "todi04.."; // Reemplaza con tu contraseña WiFi

// Crear un objeto servidor web en el puerto 80
WebServer server(80);

// Variables globales para los diez pasos
int steps1 = 0, steps2 = 0, steps3 = 0, steps4 = 0, steps5 = 0, steps6 = 0;
int steps7 = 0, steps8 = 0, steps9 = 0, steps10 = 0;
bool repeat = false; // Variable para controlar la repetición

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(2000);
        Serial.println("Conectando a WiFi...");
    }

    Serial.println("Conectado a WiFi");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());

    // Inicializar mDNS con un nombre para acceder a la red local
    if (!MDNS.begin("1brazo")) {
        Serial.println("Error al iniciar mDNS");
        while (1) {
            delay(1000);
        }
    }

    Serial.println("mDNS iniciado correctamente");

    // Configuración de pines como salida
    pinMode(DIR_PIN_1, OUTPUT);
    pinMode(STEP_PIN_1, OUTPUT);
    pinMode(DIR_PIN_2, OUTPUT);
    pinMode(STEP_PIN_2, OUTPUT);
    pinMode(DIR_PIN_3, OUTPUT);
    pinMode(STEP_PIN_3, OUTPUT);
    pinMode(RELAY_PIN, OUTPUT);  // Configurar el pin 13 (relé) como salida

    // Inicializar el pin 13 (relé) en estado LOW
    digitalWrite(RELAY_PIN, LOW);

    // Inicializar el servidor web con el formulario HTML
    server.on("/", HTTP_GET, []() {
        String html = "<html><head><style>";
        html += "body { font-family: Arial, sans-serif; background-color: #f0f0f0; color: #333; text-align: center; padding: 20px; }";
        html += "h1 { color: #4CAF50; }";
        html += "form { background-color: #ffffff; padding: 20px; border-radius: 10px; box-shadow: 0px 4px 6px rgba(0,0,0,0.1); display: inline-block; }";
        html += "input[type='number'] { padding: 5px; margin: 10px 0; width: 50px; border-radius: 5px; border: 1px solid #ccc; }";
        html += "input[type='submit'] { background-color: #4CAF50; color: white; padding: 10px 20px; border: none; border-radius: 5px; cursor: pointer; }";
        html += "input[type='submit']:hover { background-color: #45a049; }";
        html += ".container { display: flex; justify-content: space-between; margin-bottom: 20px; }";  // Contenedor principal para las columnas
        html += ".column { width: 45%; padding: 20px; background-color: #ffffff; border: 1px solid #ccc; border-radius: 8px; box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1); }";
        html += ".left-column { float: left; text-align: left; }";
        html += ".right-column { float: left; text-align: left; }";
        html += ".clearfix { clear: both; }"; // Esto asegura que los formularios no se sobrepongan
        html += ".buttons { margin-top: 20px; }";  // Estilo para los botones en la parte inferior
        html += "</style></head><body>";
        html += "<h1>Control de los Motores</h1>";
        html += "<p>Ingresa el número de pasos para que giren los motores:</p>";

        // Formulario HTML con la estructura de dos cuadros
        html += "<form action=\"/girar\" method=\"GET\">";
        html += "<div class=\"container\">";  // Contenedor principal para los cuadros
        html += "<div class=\"column left-column\">";
        html += "<label for=\"steps1\">Pasos 1 (Motor 1):</label><br>";
        html += "<input type=\"number\" name=\"steps1\" value=\"" + String(steps1) + "\" required><br>";
        html += "<label for=\"steps2\">Pasos 2 (Motor 2):</label><br>";
        html += "<input type=\"number\" name=\"steps2\" value=\"" + String(steps2) + "\" required><br>";
        html += "<label for=\"steps3\">Pasos 3 (Motor 3):</label><br>";
        html += "<input type=\"number\" name=\"steps3\" value=\"" + String(steps3) + "\" required><br>";
        html += "<label for=\"steps4\">Pasos 4 (Motor 3):</label><br>";
        html += "<input type=\"number\" name=\"steps4\" value=\"" + String(steps4) + "\" required><br>";
        html += "<label for=\"steps5\">Pasos 5 (Motor 2):</label><br>";
        html += "<input type=\"number\" name=\"steps5\" value=\"" + String(steps5) + "\" required><br>";
        html += "<label for=\"steps6\">Pasos 6 (Motor 1):</label><br>";
        html += "<input type=\"number\" name=\"steps6\" value=\"" + String(steps6) + "\" required><br>";
        html += "</div>";

        html += "<div class=\"column right-column\">";
        html += "<label for=\"steps7\">Pasos 7 (Motor 2):</label><br>";
        html += "<input type=\"number\" name=\"steps7\" value=\"" + String(steps7) + "\" required><br>";
        html += "<label for=\"steps8\">Pasos 8 (Motor 3):</label><br>";
        html += "<input type=\"number\" name=\"steps8\" value=\"" + String(steps8) + "\" required><br>";
        html += "<label for=\"steps9\">Pasos 9 (Motor 3):</label><br>";
        html += "<input type=\"number\" name=\"steps9\" value=\"" + String(steps9) + "\" required><br>";
        html += "<label for=\"steps10\">Pasos 10 (Motor 2):</label><br>";
        html += "<input type=\"number\" name=\"steps10\" value=\"" + String(steps10) + "\" required><br>";
        html += "</div>";

        html += "</div>"; // Cierra el contenedor de las columnas

        html += "<input type=\"submit\" value=\"Girar\">";
        html += "</form>";

        // Botones para repetir o detener en la parte inferior
        html += "<div class=\"buttons\">";
        html += "<form action=\"/repetir\" method=\"GET\">";
        html += "<input type=\"submit\" value=\"Repetir\">";
        html += "</form>";

        html += "<form action=\"/detener\" method=\"GET\">";
        html += "<input type=\"submit\" value=\"Detener\">";
        html += "</form>";
        html += "</div>"; // Fin de los botones

        html += "</body></html>";
        server.send(200, "text/html", html);
    });

    // Ruta para girar los motores
    server.on("/girar", HTTP_GET, []() {
        if (server.hasArg("steps1") && server.hasArg("steps2") && server.hasArg("steps3") &&
            server.hasArg("steps4") && server.hasArg("steps5") && server.hasArg("steps6") &&
            server.hasArg("steps7") && server.hasArg("steps8") && server.hasArg("steps9") &&
            server.hasArg("steps10")) {

            steps1 = server.arg("steps1").toInt();
        steps2 = server.arg("steps2").toInt();
        steps3 = server.arg("steps3").toInt();
        steps4 = server.arg("steps4").toInt();
        steps5 = server.arg("steps5").toInt();
        steps6 = server.arg("steps6").toInt();
        steps7 = server.arg("steps7").toInt();
        steps8 = server.arg("steps8").toInt();
        steps9 = server.arg("steps9").toInt();
        steps10 = server.arg("steps10").toInt();

        girarMotores();

        server.sendHeader("Location", "/");
        server.send(303);
            } else {
                server.sendHeader("Location", "/");
                server.send(303);
            }
    });

    server.on("/repetir", HTTP_GET, []() {
        repeat = true;
        server.sendHeader("Location", "/");
        server.send(303);
    });

    server.on("/detener", HTTP_GET, []() {
        repeat = false;
        server.sendHeader("Location", "/");
        server.send(303);
    });

    server.begin();
}

void loop() {
    server.handleClient();

    if (repeat) {
        girarMotores();
    }
}

// Función para girar los motores
void girarMotores() {
    rotateMotor(DIR_PIN_1, STEP_PIN_1, steps1);
    delay(1000);
    rotateMotor(DIR_PIN_2, STEP_PIN_2, steps2);
    delay(1000);

    rotateMotor(DIR_PIN_3, STEP_PIN_3, steps3);
    // Activar el pin 13 (relé) cuando se inicie el paso 3, sin importar si los pasos son positivos o negativos
    if (abs(steps3) > 0) {  // Verificamos el valor absoluto de los pasos
        digitalWrite(RELAY_PIN, HIGH);  // Activar relé (pin 13)
    }
    delay(1000);

    rotateMotor(DIR_PIN_3, STEP_PIN_3, steps4);
    delay(1000);
    rotateMotor(DIR_PIN_2, STEP_PIN_2, steps5);
    delay(1000);
    rotateMotor(DIR_PIN_1, STEP_PIN_1, steps6);
    delay(1000);
    rotateMotor(DIR_PIN_2, STEP_PIN_2, steps7);
    delay(1000);
    rotateMotor(DIR_PIN_3, STEP_PIN_3, steps8);
    delay(1000);

    // Desactivar el pin 13 (relé) después del paso 8
    if (abs(steps8) > 0) {  // Verificamos el valor absoluto de los pasos
        digitalWrite(RELAY_PIN, LOW);  // Desactivar relé (pin 13)
    }
    delay(1000);

    rotateMotor(DIR_PIN_3, STEP_PIN_3, steps9);
    delay(1000);

    rotateMotor(DIR_PIN_2, STEP_PIN_2, steps10);
    delay(1000);
}

// Función para girar un motor según los pasos ingresados
void rotateMotor(int dirPin, int stepPin, int steps) {
    digitalWrite(dirPin, steps > 0 ? HIGH : LOW);
    steps = abs(steps);

    for (int i = 0; i < steps; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(800);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(800);
    }
}
#CODIGO 1BRAZO
