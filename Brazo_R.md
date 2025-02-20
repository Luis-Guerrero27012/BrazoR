# Brazo Robótico Cartesiano

# 🎯 Objetivos
## General
- Construir un brazo cartesiano de 3 ejes con microcontrolador y una base giratoria, utilizando motores paso a paso.

## Específicos
- Investigar los principios de funcionamiento de un brazo cartesiano, sus especificaciones y el control de motores paso a paso con un microcontrolador.-
-  Calcular la potencia y la fuerza requerida en los ejes del brazo, considerando peso, estabilidad y capacidad de carga.
- Construir el brazo cartesiano de 3 ejes, integrando los motores paso a paso y el microcontrolador con la base giratoria.
- Analizar el rendimiento y precisión mediante pruebas de movimiento de ejes y control.

  ## 📌 Características
### ¿Qué es un brazo cartesiano?
Un sistema mecánico que utiliza movimientos lineales a lo largo de tres ejes ortogonales (X, Y, Z). Se basa en la geometría cartesiana, donde cada eje es controlado independientemente.

### Robótica Industrial
Según la norma ISO 8373:2012, un robot es un manipulador multipropósito, reprogramable, con control automático y programable en tres o más ejes.

### Clasificación de brazos robóticos
![Image](https://github.com/user-attachments/assets/d89869be-9f38-4406-99eb-73e7f4e1adf2)
- **Cartesianos:** Con tres articulaciones prismáticas en un sistema de coordenadas cartesiano.
- **SCARA:** Dos articulaciones rotatorias paralelas y un eje vertical.
- **Articulados:** Mayor movilidad con hasta seis grados de libertad.
- **Paralelos o Delta:** Brazos con articulaciones prismáticas o rotatorias concurrentes.
- **Cilíndricos:** Sus ejes forman un sistema de coordenadas cilíndrico.

### Sistemas de Movimientos en Brazos Cartesianos

- **Eje X:** Movimiento horizontal (izquierda/derecha).
- **Eje Y:** Movimiento en el plano horizontal (adelante/atrás).
- **Eje Z:** Movimiento vertical (arriba/abajo).

### Código G

G-Code es un lenguaje estándar para la mecanización CNC, utilizado en la robótica para controlar el movimiento de las máquinas.

---

## Componentes Clave del Sistema

### Motores Paso a Paso

Son motores eléctricos trifásicos que ofrecen alta eficiencia energética. Ejemplo: **Motores NEMA 17**.

## Componentes Clave del Sistema

### Motores Paso a Paso
Son motores eléctricos trifásicos que ofrecen alta eficiencia energética. Ejemplo: **Motores NEMA 17**.

![Image](https://github.com/user-attachments/assets/5feac370-d209-46e9-9c3a-86db31dc4caa)


### Engranajes y Transmisión

- **Acoples:** Unen ejes para sincronización.
- **Tornillo sin fin:** Conversión de movimiento rotatorio.
- **Ejes acerados:** Componentes mecánicos de alta resistencia.
- **Correas dentadas:** Transmisión de movimiento precisa.
- **Rodamientos:** Reducen la fricción en el movimiento.

---

## Control y Electrónica

### Microprocesador

Controla y ejecuta instrucciones dentro del sistema.

### Programación con Arduino

Plataforma de código abierto basada en C/C++.

### Driver A4988

Controla motores paso a paso mediante señales de control.

### Fuente de Poder

Fuente de 500W con múltiples salidas de voltaje (+12V, +5V, +3.3V).

---

## Diseño y Simulación 3D

![Image](https://github.com/user-attachments/assets/8e27e7ab-1b6c-4ee7-a800-d591a43c64f7)

![Image](https://github.com/user-attachments/assets/4ca305b4-8a14-4187-ad84-7c360eeae879)


### Materiales de Impresión

- **PLA:** Biodegradable, ideal para prototipos.
- **ABS:** Mayor resistencia y durabilidad.
- **PETG:** Combinación de resistencia y flexibilidad.
- **Nylon:** Alta resistencia mecánica.
- **Resina:** Ideal para detalles finos en modelos complejos.

  ### Cálculos de Fuerzas y Torque

#### Fórmulas:

- **Volumen de la barra:**
  ```
  V = π (d/2)^2 * L
  ```
- **Masa de la barra:**
  ```
  m = V * ρ
  ```
- **Peso de la barra:**
  ```
  W = m * g
  ```
- **Torque:**
  ```
  T = F * distancia
  ```

---

## Simulación y Desarrollo del Brazo Robótico

- **Perfiles de aluminio serie V20**
- **Sistema de sujeción con electroimán**
- **ESP32 como microcontrolador**

---

## Conclusión

El diseño y construcción de un brazo cartesiano de 3 ejes con microcontrolador permite un control preciso en aplicaciones industriales y educativas. La combinación de materiales adecuados, cálculos mecánicos y programación eficiente garantizan un funcionamiento óptimo.

---

## 📷 Imágenes
### Esquema del Brazo
![Image](https://github.com/user-attachments/assets/99e8b9d5-a120-4ba8-838d-2c55e0156355)

### Circuito de conexión
![Image](https://github.com/user-attachments/assets/725cbcff-e970-430f-b057-2a2048067d81)

![Image](https://github.com/user-attachments/assets/42c8c51f-d08f-4478-98b2-434e1774dad8)


## 🛠️ Componentes
- **Microcontrolador**: ESP32.
- **Motores paso a paso** con drivers.
- **Estructura** impresa en 3D.
- **Fuente de alimentación** adecuada.
- **Software** en Qt6/C++.

## ⚙️ Instalación
1. Clona este repositorio:
   ```bash
   git clone https://github.com/tuusuario/brazo_cartesiano.git
   ```
2. Instala las dependencias necesarias.
3. Compila y carga el código en el microcontrolador.
4. Ejecuta la interfaz de usuario en Qt.

## 🖥️ Interfaz de Control
La interfaz permite controlar los movimientos del brazo de forma manual o automatizada.

![Interfaz de usuario](https://via.placeholder.com/800x400.png?text=Interfaz+de+Control)

## 📜 Licencia
Este proyecto está bajo la licencia **MIT**.

---
¡Contribuciones y mejoras son bienvenidas! 😊
