# <div style='text-align: right'> <div style='color: black'> ***Manual de Funcionamiento del Brazo Cartesiano***

![brazo](https://github.com/user-attachments/assets/f08b59f2-8ff0-4c38-9fe9-b6c48a09bd60)


## ÍNDICE 
1. [INTRODUCCIÓN](#INTRO)
2. [MEDIDAS DE SEGURIDAD](#SEGURIDAD)
3. [DESCRIPCIÓN DEL EQUIPO](#DESCRIPCIÓN)
4. [CONFIGURACIÓN](#CONFI)



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
![Esquema2](https://github.com/user-attachments/assets/04218100-8210-4bef-a13f-e359339fee51) <br>

***
<a id='CONFI'></a>

## **4. Configuración**
### Conexión de circuito <br>
![diagrama_motores](https://github.com/user-attachments/assets/a43113c3-6a09-47fe-b55e-b84ded706985) <br>
(Arduino.cc,2022)
## **Operación** <br>
**Inicio del sistema** <br>
   1. Verificar la alimentación eléctrica y encender la ESP32.
   2.  Revisar que los motores Nema 17 y los sensores de fin de carrera estén operativos.
   3.  Calibrar la posición inicial utilizando los sensores de fin de carrera.
   4.  Activar el sistema y ejecutar pruebas de movimiento sin carga. <br>

**Uso del electroimán** <br>
El electroimán se alimenta con 12V y su encendido se controla con un relé, activado por la ESP32. Cuando el brazo cartesiano se mueve hasta la posición del objeto metálico, la ESP32 activa el relé, permitiendo el flujo de corriente al electroimán, esto genera un campo magnético que atrae y sujeta el material posteriormente, el brazo cartesiano transporta el material hasta la ubicación deseada. Para liberar el objeto, la ESP32 apaga el relé, interrumpiendo el flujo de corriente; como resultado, el campo magnético desaparece y el material cae en su lugar.

**Interfaz** <br>
El modo de operación es remoto debido a que se controla el brazo mediante la vía Wi-Fi/Blluetooth desde una PC o la aplicación móvil.
- Configuración de Pasos en motores PAP <br>
La interfaz se vera de la manera siguiente: <br>
![interfaz2 jpg](https://github.com/user-attachments/assets/8416f23b-ae66-40e2-910d-bbf91e88a8dc) <br>
Para configurar los pasos tomar en cuenta que:
- Motor 1 corresponde al eje y que mueve la base, tiene un máximo de 90° de giro.
- Motor 2 corresponde al eje x, tiene un máximo de 15 cm. de avance.
- Motor 3 corresponde al eje z, tiene un máximo de 5cm. de avance.
Referente a los pasos ingresar: <br>

**Motor 1**
- Pasos 1: 2000
- Pasos 6: 1000 

**Motor 2**
- Pasos 2: 1000
- Pasos 5: -1000

**Motor 3**
- Pasos 3: 1000
- Pasos 4: -1000

Finaliza dando click en Girar. <br>
Repetir para realizar el ciclo. <br>
Detener para finalizar el ciclo. 

