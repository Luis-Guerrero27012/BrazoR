## <div style='text-align: right'> <div style='color: black'> ***Manual de Funcionamiento del Brazo Cartesiano***

![Brazo](brazo.png)

<img src="brazo.png" width="400">

<img src="brazo-removebg-preview.png" width = 500 height = 500 aling = right figclass= margin-caption>

## ÍNDICE 
1. [INTRODUCCIÓN](#INTRO)
2. [MEDIDAS DE SEGURIDAD](#SEGURIDAD)
2. [DESCRIPCIÓN DEL EQUIPO](#DESCRIPCIÓN)



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

### **3. DESCRIPCIÓN DEL EQUIPO**



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
