# <div style='text-align: right'> <div style='color: black'> ***Manual de Funcionamiento del Brazo Cartesiano***

![brazo](https://github.com/user-attachments/assets/f08b59f2-8ff0-4c38-9fe9-b6c48a09bd60)


## ÍNDICE 
1. [INTRODUCCIÓN](#INTRO)
2. [MEDIDAS DE SEGURIDAD](#SEGURIDAD)
3. [DESCRIPCIÓN DEL EQUIPO](#DESCRIPCIÓN)



***
<a id='INTRO'></a>

## **1. INTRODUCCIÓN**
El presente documento describe la funcionalidad del brazo cartesiano comandado por un microcontrolador. El sistema está diseñado para mover un objeto metálico desde su punto inicial hasta diferentes grados de movimiento. Este manual proporciona directrices detalladas para la operación del brazo cartesiano, indicando los procedimientos de uso controlando de movimiento en forma tridimensional mediante una interfaz entre el sistema y un usuario.


***
<a id='SEGURIDAD'></a>

## **2. MEDIDAS DE SEGURIDAD**
Durante la operación tenga en cuenta:
- El uso obligatorio de guantes y gafas de protección.
- Observar que el equipo no tenga piezas sueltas.
- Asegurar una correcta ventilación del área de trabajo para evitar acumulación de calor en los motores.
- Mantener el área de trabajo limpia y libre de obstrucciones.
- No acercar manos u objetos a las partes móviles del brazo.
- Realizar pruebas de los grados de movimiento.
- Verificar que el equipo se encuentre desconectado antes de realizar cualquier ajuste.


***
<a id='DESCRIPCIÓN'></a>

## **3. DESCRIPCIÓN DEL EQUIPO**
### Especificaciones Técnicas

### Componentes Principales
- **Motores**: 3x Nema 17 <br>
![motor](https://github.com/user-attachments/assets/4e83dea2-4d1b-4a0c-bb07-5d7d4a59ddc8)
- **Controlador**: ESP32 <br>
![esp](https://github.com/user-attachments/assets/e8e96de7-8906-41bf-a7c2-4ce6c124e8fa) 
- **Drivers**: A4988 <br>
![driver](https://github.com/user-attachments/assets/a7325789-c9fb-4e27-a54d-1f2c84f47243)
- **Sensor**: Hall <br>
![hall](https://github.com/user-attachments/assets/a845416e-9d73-4845-8cb2-a8ed4fad64af)
- **Correa Dentada**: X1 <br>
![correa](https://github.com/user-attachments/assets/dca61f18-8519-4507-8bbb-8c046366be0d)
- **Rodamiento radial**: x4 <br>
![rodami](https://github.com/user-attachments/assets/f1d9bb19-74bf-4549-8e1c-f30bf4d0f59c)
- **Rodamiento Excéntrico**: x2 <br>
![rodamiento](https://github.com/user-attachments/assets/81a047b1-8ddc-4b0c-8b9c-f1a2b0dc933b)
### Esquema <br>
![Esquema1](https://github.com/user-attachments/assets/7fadaf5f-3fbc-4115-9198-4e0989a74853) <br>
![Esquema2](https://github.com/user-attachments/assets/04218100-8210-4bef-a13f-e359339fee51)

## **4. Instalación y Configuración Inicial**
### Conexión Eléctrica y cableado
(Conexión de motores,drivers,sensores y alimentación )

### Calibración inicial
(Conexión de motores,drivers,sensores y alimentación )

## **5. Operación** <br>
El modo de operación es remoto debido a que se controla el brazo mediante la vía Wi-Fi/Blluetooth desde una PC o la aplicación móvil.
- Uso de comandos
- Configuración de Pasos en motores PAP
- Uso del electroimán y sensores en tareas automatizadas
- 



###**6. Inicio del sistema** <br>
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
