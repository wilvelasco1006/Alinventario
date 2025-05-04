# 📦 Alinventario

**Alinventario** es una aplicación de consola desarrollada en **C++** para gestionar inventarios, registrar compras y ventas, y llevar un historial detallado de los movimientos de productos.

---

## 🚀 Características principales

🔹 **Registrar Compras**  
Permite ingresar productos al inventario con los siguientes datos:
- Nombre, código y descripción del producto.
- Cantidad comprada.
- Precio de compra y precio de venta.
- Nombre del proveedor.
- Fecha de la compra.

🔹 **Registrar Ventas**  
Facilita la venta de productos:
- Búsqueda por código del producto.
- Validación de existencia en inventario.
- Descuento automático de unidades vendidas.
- Registro del cliente y la fecha.

🔹 **Mostrar Inventario**  
Muestra la lista de productos disponibles junto con:
- Nombre, código, descripción.
- Cantidad disponible.
- Precio de compra y venta.

🔹 **Mostrar Historial**  
Muestra un historial completo de:
- Compras y ventas realizadas.
- Fecha, tipo de movimiento y proveedor/cliente asociado.
- Productos involucrados con cantidades.

🔹 **Salir**  
Finaliza el programa de manera segura.

---

## 🧱 Estructura de Clases

| Clase              | Responsabilidad                                                                 |
|-------------------|----------------------------------------------------------------------------------|
| `class_producto`   | Modela un producto individual.                                                   |
| `class_movimiento` | Registra una operación (compra o venta) con sus productos y datos asociados.     |
| `class_gestion`    | Controla el inventario, permite registrar compras, ventas y visualizar historial. |
| `class_inicio`     | Gestiona el menú principal del sistema e interacción del usuario.                |

---
## 📌 Requisitos

- Compilador compatible con **C++11** o superior (como `g++`, `clang++`, o uno en línea).
- Consola o terminal para interacción con el programa.
- No se requieren librerías externas.
## ⚙️ Cómo compilar y ejecutar

Puedes compilar este programa localmente usando un compilador de C++ como `g++`:

```bash
g++ -o Alinventario Alinventario.cpp
./Alinventario
```
## 💡 Alternativa recomendada

Si tienes dificultades para configurar el compilador en tu equipo, puedes usar este compilador en línea:

🔗 [Programiz C++ Online Compiler](https://www.programiz.com/cpp-programming/online-compiler/)

1. Copia y pega el contenido del archivo `.cpp` en el editor.  
2. Haz clic en el botón **"Run"** para ejecutar el programa.
