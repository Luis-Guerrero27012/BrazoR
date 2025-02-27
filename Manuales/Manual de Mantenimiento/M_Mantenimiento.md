# <div style='text-align: right'> <div style='color: red'> ***Manual de Mantenimiento del Brazo Cartesiano***

![imagen](https://github.com/user-attachments/assets/c7ebbe3d-354b-46b3-8bb3-d5b919fb551e)
           
Este manual proporciona los procedimientos de mantenimiento necesarios para garantizar el correcto funcionamiento del brazo robótico equipado con tres motores NEMA 17 y un electroimán. Se detallan las rutinas de inspección, limpieza, ajuste y lubricación para prolongar la vida útil del equipo.

## Herramientas y Materiales

- Destornilladores de punta plana y de estrella
- Juego de llaves hexagonales
- Multímetro
- Lubricante para rodamientos (WD-40)
- Aire comprimido
- Trapo de microfibra
- Alcohol isopropílico
- Cepillo suave
- Guantes de seguridad
- Gafas de protección
- Bridas plásticas

## Mantenimiento Preventivo

### Inspección General (Frecuencia: Semanal)

- Revisión de cables y conectores: Verificar que no haya cables sueltos, pelados o dañados. Si se detecta algún daño, reemplazar de inmediato.
  
![imagen](https://github.com/user-attachments/assets/20d37110-8253-4d42-8df6-6b97bf393bb8)

- Verificación de temperatura en motores: Usar un termómetro infrarrojo para medir la temperatura de los motores NEMA 17 después de un ciclo de operación. Si excede los 60°C, investigar la causa (sobrevoltaje, carga excesiva, ventilación insuficiente).

![imagen](https://github.com/user-attachments/assets/ae59ee43-5b97-4156-8711-b1df90046894)

- Inspección del electroimán: Observar si hay acumulación de partículas metálicas que puedan afectar su rendimiento. Si es necesario, proceder a la limpieza.

![imagen](https://github.com/user-attachments/assets/152e8b4b-f957-4256-95a9-12eafcbd8d5a)

- Verificación del estado de los drivers A4988: Revisar si presentan sobrecalentamiento o conexiones sueltas.

![imagen](https://github.com/user-attachments/assets/4d52ea0e-147e-4915-aa95-684e45213413)
 
- Revisión de la fuente de energía: Verificar que la fuente de CPU proporcione un voltaje estable y sin fluctuaciones.

![imagen](https://github.com/user-attachments/assets/b794f6cf-c611-49a0-ba2e-02f9dcc5ee88)


### Limpieza (Frecuencia: Mensual)

- Desconectar la energía antes de manipular cualquier parte del brazo robótico.

![imagen](https://github.com/user-attachments/assets/2459ce59-6673-4fae-be48-87bbf1cd104a)


- Limpieza de la estructura: Pasar un trapo de microfibra seco o ligeramente humedecido con alcohol isopropílico para eliminar polvo y suciedad.

![imagen](https://github.com/user-attachments/assets/9b9322a3-7262-4938-84a0-03b95b096ee8)


- Uso de aire comprimido: Aplicar aire comprimido en las zonas de difícil acceso, como ventiladores de los motores y rendijas del sistema.

![imagen](https://github.com/user-attachments/assets/827d10ec-aed5-4724-a432-4b3e899bf176)


- Limpieza de engranajes y base: Aplicar alcohol isopropílico con un cepillo suave para eliminar grasa acumulada y residuos de suciedad.

![imagen](https://github.com/user-attachments/assets/018779ca-3b04-4d98-b009-3e1cb36264ef)


- Limpieza del electroimán: Pasar un cepillo suave para eliminar residuos metálicos adheridos y, si es necesario, utilizar un trapo húmedo con alcohol.

![imagen](https://github.com/user-attachments/assets/c744e55f-31b6-4eff-ab0e-6173f8f6a9bd)
![imagen](https://github.com/user-attachments/assets/ee28066e-e028-4033-ad11-4015eecd63c4)


### Lubricación (Frecuencia: Cada 3 meses)

- Aplicación de lubricante en rodamientos: Usar un lubricante adecuado para rodamientos.

![imagen](https://github.com/user-attachments/assets/26517354-5986-400c-9de4-0b287d5b095d)


- Engrasado de engranajes de la base: Aplicar una capa delgada de grasa de litio en los dientes del engranaje grande para reducir la fricción y desgaste.

![imagen](https://github.com/user-attachments/assets/f0ec6373-c4f1-43e4-9bb6-f8e4591a8e8a)


- Distribución uniforme del lubricante: Girar manualmente los ejes varias veces después de la aplicación para garantizar una distribución uniforme.

![imagen](https://github.com/user-attachments/assets/7e7c53de-d975-4821-9506-3826d8bae6e7)



### Ajuste de Componentes (Frecuencia: Cada 6 meses)

- Revisión y ajuste de tornillos: Usar llaves hexagonales para comprobar la fijación de los motores y otros componentes.

![imagen](https://github.com/user-attachments/assets/5b8f565d-92ed-46ed-87e2-af4226af2a2d)


- Verificación de la tensión de correas (si aplica): Ajustar las correas para evitar holguras que puedan provocar imprecisiones en el movimiento del brazo.

![imagen](https://github.com/user-attachments/assets/d4813fcc-0541-4aa1-ab0b-15a46d7aacb2)


- Acomodación de cables: Revisar que los cables no obstruyan el movimiento y, si es necesario, fijarlos con bridas plásticas para mantener un orden adecuado.

![imagen](https://github.com/user-attachments/assets/d07835c0-d592-471c-857a-484f4197bc58)



## Mantenimiento Correctivo

### Problemas Comunes y Soluciones

| Problema | Causa Probable | Solución |
|----------|----------------|----------|
| El motor no responde | Cable suelto o desconectado | Revisar conexiones y ajustar |
| Ruidos anormales | Falta de lubricación en engranajes o piezas desajustadas | Aplicar lubricante y ajustar fijaciones |
| Pérdida de fuerza del electroimán | Acumulación de suciedad o falla eléctrica | Limpiar el electroimán o verificar voltaje |
| Movimiento impreciso | Tornillos flojos, desalineación o software mal calibrado | Ajustar tornillería, calibrar sensores y verificar configuración del software |
| Sobrecalentamiento del motor | Exceso de carga, mala ventilación o problema en la alimentación eléctrica | Reducir carga, mejorar ventilación y revisar voltaje |

## Seguridad y Recomendaciones

- Desconexión eléctrica: Siempre desconectar la fuente de energía antes de realizar cualquier mantenimiento.
- Uso de equipo de protección personal (EPP): Utilizar guantes y gafas de seguridad para prevenir accidentes.
- Supervisión en manipulación: Evitar el contacto directo con el electroimán cuando esté energizado.
- Evitar sobrecargas: No exceder los límites de peso recomendados para evitar fallos mecánicos.
- Entorno seco: Realizar el mantenimiento en ambientes libres de humedad para evitar cortocircuitos.

## Registro de Mantenimiento

| Fecha | Técnico Responsable | Tareas Realizadas | Observaciones | Próximo Mantenimiento|
|-------|---------------------|-------------------|---------------|----------------------|
|       |                     |                   |               |                      |
|-------|---------------------|-------------------|---------------|----------------------|
|       |                     |                   |               |                      |
|-------|---------------------|-------------------|---------------|----------------------|
|       |                     |                   |               |                      |
|-------|---------------------|-------------------|---------------|----------------------|
|       |                     |                   |               |                      |
|-------|---------------------|-------------------|---------------|----------------------|
|       |                     |                   |               |                      |










