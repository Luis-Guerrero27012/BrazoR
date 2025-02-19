# Manual de funcionamiento
### **1. Introducción**
El presente documento proporciona directrices detalladas para la operación  y mantenimiento del brazo cartesiano, incluyendo procedimientos de uso, diseño, planes de colocación de equipos, programación de mantenimiento y protocolos de emergencia.

### **2. Características Técnicas**
- **Motores**: 3x Nema 17
- **Controlador**: ESP32
- **Drivers**: A4988
- **Sensor**: Hall
- **Correa Dentada**:
- **Rodamiento radial**: x4
- **Rodamiento Exéntrico**: x2
- 
# *Añadir dibujo con señalamiento de las piezas*

### **3. Procedimientos de Operación**
- **3.1. Inicio del sistema** <br>
   1. Verificar la alimentación eléctrica y encender la ESP32.
   2.  Revisar que los motores Nema 17 y los sensores de fin de carrera estén operativos.
   3.  Calibrar la posición inicial utilizando los sensores de fin de carrera.
   4.  Activar el sistema y ejecutar pruebas de movimiento sin carga.
- **3.2. Operación del Brazo Cartesiano** <br>
   1. Mover el brazo a la posición deseada utilizando el software de control.
   2. Activar el electroimán para sujetar el material metálico.
   3. Transportar el material a 90 grados y descender el brazo.
   4. Desactivar el electroimán para liberar el material.
   5. Retornar el brazo a su posición inicial.
### **4. Uso**
- Para mover el brazo, enviar comandos desde la interfaz.
- Para resetear la posición, presionar el botón de home.
