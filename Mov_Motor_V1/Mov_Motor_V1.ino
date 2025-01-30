// Configuración y prueba: Motores de pasos, Drivers A4988 y ESP32

// Definición de pines para cada eje
#define x_paso 15   // Pin STEP para Motor X
#define x_dire 2    // Pin DIR para Motor X
#define x_habi 4    // Pin ENABLE para Motor X

#define y_paso 25   // Pin STEP para Motor Y
#define y_dire 32   // Pin DIR para Motor Y
#define y_habi 33   // Pin ENABLE para Motor Y

#define z_paso 12   // Pin STEP para Motor Z
#define z_dire 14   // Pin DIR para Motor Z
#define z_habi 27   // Pin ENABLE para Motor Z

#define boton 26    // Pin para el pulsador de retorno a cero

// Configuración de velocidades y tiempos
int retardo = 3000; // Retardo en microsegundos (velocidad de giro)
int pasos_x = 100;   // Número de pasos para el motor X
int pasos_y = 100;   // Número de pasos para el motor Y (ajustado para prueba)
int pasos_z = 100;   // Número de pasos para el motor Z

void setup() {
  // Configuración de los pines como salida
  pinMode(x_paso, OUTPUT);
  pinMode(x_dire, OUTPUT);
  pinMode(x_habi, OUTPUT);

  pinMode(y_paso, OUTPUT);
  pinMode(y_dire, OUTPUT);
  pinMode(y_habi, OUTPUT);

  pinMode(z_paso, OUTPUT);
  pinMode(z_dire, OUTPUT);
  pinMode(z_habi, OUTPUT);

  // Configuración del botón
  pinMode(boton, INPUT_PULLUP); // Botón con resistencia de pull-up interna

  // Inicialización del puerto serial para depuración
  Serial.begin(115200);
  Serial.println("Setup completo. Iniciando...");
}

void loop() {
  // Verificar si el botón está presionado
  if (digitalRead(boton) == LOW) {
    Serial.println("Botón presionado. Regresando motor X a la posición inicial...");
    moverMotor(x_paso, x_dire, x_habi, pasos_x, LOW); // Mover en dirección contraria
  } else {
    // Giro en una dirección
    Serial.println("Girando en una dirección...");
    giroSimultaneo(pasos_x, pasos_y, pasos_z, HIGH, HIGH, HIGH);
    delay(500);

    // Giro en dirección contraria (regresar a cero)
    Serial.println("Regresando a la posición inicial...");
    giroSimultaneo(pasos_x, pasos_y, pasos_z, LOW, LOW, LOW);
    delay(500);
  }
}

// Función para controlar el giro simultáneo de los motores
void giroSimultaneo(int pasosX, int pasosY, int pasosZ, int dirX, int dirY, int dirZ) {
  int pasos_max = max(pasosX, max(pasosY, pasosZ));
  int contadorX = 0, contadorY = 0, contadorZ = 0;

  digitalWrite(x_habi, LOW);
  digitalWrite(y_habi, LOW);
  digitalWrite(z_habi, LOW);

  digitalWrite(x_dire, dirX);
  digitalWrite(y_dire, dirY);
  digitalWrite(z_dire, dirZ);

  for (int i = 0; i < pasos_max; i++) {
    if (contadorX < pasosX) {
      digitalWrite(x_paso, HIGH);
      delayMicroseconds(retardo);
      digitalWrite(x_paso, LOW);
      delayMicroseconds(retardo);
      contadorX++;
    }

    if (contadorY < pasosY) {
      digitalWrite(y_paso, HIGH);
      delayMicroseconds(retardo);
      digitalWrite(y_paso, LOW);
      delayMicroseconds(retardo);
      contadorY++;
    }

    if (contadorZ < pasosZ) {
      digitalWrite(z_paso, HIGH);
      delayMicroseconds(retardo);
      digitalWrite(z_paso, LOW);
      delayMicroseconds(retardo);
      contadorZ++;
    }
  }

  digitalWrite(x_habi, HIGH);
  digitalWrite(y_habi, HIGH);
  digitalWrite(z_habi, HIGH);

  Serial.print("Motor X completó pasos: ");
  Serial.println(contadorX);
  Serial.print("Motor Y completó pasos: ");
  Serial.println(contadorY);
  Serial.print("Motor Z completó pasos: ");
  Serial.println(contadorZ);
}

// Función para mover un motor a pasos definidos
void moverMotor(int pinPaso, int pinDire, int pinHabi, int pasos, int direccion) {
  digitalWrite(pinHabi, LOW);
  digitalWrite(pinDire, direccion);

  for (int i = 0; i < pasos; i++) {
    digitalWrite(pinPaso, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(pinPaso, LOW);
    delayMicroseconds(retardo);
  }

  digitalWrite(pinHabi, HIGH);
}
