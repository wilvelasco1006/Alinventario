#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class class_producto {
public:
    string atr_nombre_producto;
    string atr_codigo_producto;
    string atr_descripcion_producto;
    int atr_cantidad_producto;
    double atr_precio_compra_producto;
    double atr_precio_venta_producto;
    
    class_producto(const string& var_n, const string& var_cod, const string& var_desc, int cant, double var_pCompra, double var_pVenta)
        : atr_nombre_producto(var_n), atr_codigo_producto(var_cod), atr_descripcion_producto(var_desc),
        atr_cantidad_producto(cant), atr_precio_compra_producto(var_pCompra), atr_precio_venta_producto(var_pVenta) {}

    void met_mostrar_producto(int var_cantidad) const {
        cout << "Nombre: " << atr_nombre_producto << "\nCódigo: " << atr_codigo_producto << "\nDescripción: " << atr_descripcion_producto
            << "\nCantidad: " << var_cantidad << "\nPrecio de compra: $" << atr_precio_compra_producto << "\nPrecio de venta: $" << atr_precio_venta_producto << endl;
    }
};

class class_movimiento {
public:
    string atr_fecha_movimiento;
    string atr_tipo_movimiento;
    string atr_proveedor_cliente_movimiento;
    vector<pair<class_producto, int>> vec_productos_movimiento;

    class_movimiento(string var_f, string var_t, string var_pc) : atr_fecha_movimiento(var_f), atr_tipo_movimiento(var_t), atr_proveedor_cliente_movimiento(var_pc) {}

    void met_agregar_producto(const class_producto& obj_producto, int cantidad) {
        vec_productos_movimiento.push_back(make_pair(obj_producto, cantidad));
    }

    void met_mostrar_movimiento() const {
        cout << "Fecha: " << atr_fecha_movimiento << "\nTipo: " << atr_tipo_movimiento << "\nProveedor/Cliente: " << atr_proveedor_cliente_movimiento << "\nProductos:" << endl;
        for (const auto& vec_par : vec_productos_movimiento) {
            vec_par.first.met_mostrar_producto(vec_par.second);
            cout << "--------" << endl;
        }
    }
};

class class_gestion {
public:
    vector<class_producto> vec_inventario;
    vector<class_movimiento> vec_historial;

    void met_registrar_compra() {
        string var_proveedor, var_numero_factura, var_fecha_compra;
        cout << "Ingrese el nombre del proveedor: ";
        cin >> var_proveedor;
        cout << "Ingrese el número de factura: ";
        cin >> var_numero_factura;
        cout << "Ingrese la fecha de compra (YYYY-MM-DD): ";
        cin >> var_fecha_compra;

        class_movimiento obj_nuevo_movimiento(var_fecha_compra, "Compra", var_proveedor);

        while (true) {
            string var_nombre, var_codigo, var_descripcion;
            int var_cantidad;
            double var_precio_compra, var_precio_venta;

            cout << "Ingrese el nombre del producto (o 'fin' para terminar): ";
            cin >> var_nombre;
            if (var_nombre == "fin") {
                break;
            }

            cout << "Ingrese la descripción del producto: ";
            cin.ignore(); // Limpiar el buffer del teclado
            getline(cin, var_descripcion);

            cout << "Ingrese el código del producto: ";
            cin >> var_codigo;

            cout << "Ingrese la cantidad comprada: ";
            cin >> var_cantidad;

            cout << "Ingrese el precio de compra del producto: $";
            cin >> var_precio_compra;
            
            cout << "Ingrese el precio de venta del producto: $";
            cin >> var_precio_venta;

            class_producto obj_nuevo_producto(var_nombre, var_codigo, var_descripcion, var_cantidad, var_precio_compra, var_precio_venta);
            vec_inventario.push_back(obj_nuevo_producto);

            // Agregar movimiento al historial
            obj_nuevo_movimiento.met_agregar_producto(obj_nuevo_producto, var_cantidad);
        }

        vec_historial.push_back(obj_nuevo_movimiento);
        cout << "Compra registrada exitosamente." << endl;
    }

    void met_registrar_venta() {
        string var_cliente, var_fecha_venta;
        cout << "Ingrese el nombre del cliente: ";
        cin.ignore(); // Limpiar el buffer del teclado
        getline(cin, var_cliente);
        cout << "Ingrese la fecha de venta (YYYY-MM-DD): ";
        cin >> var_fecha_venta;

        class_movimiento obj_nuevo_movimiento(var_fecha_venta, "Venta", var_cliente);

        while (true) {
            string var_codigo_producto;
            int var_cantidad;
            cout << "Ingrese el codigo del producto (o 'fin' para terminar): ";
            cin >> var_codigo_producto;
            if (var_codigo_producto == "fin") {
                break;
            }

            auto var_it = met_buscar_producto(var_codigo_producto);
            if (var_it != vec_inventario.end()) {
                cout << "Ingrese la cantidad vendida: ";
                cin >> var_cantidad;
                if (var_it->atr_cantidad_producto >= var_cantidad) {
                    var_it->atr_cantidad_producto -= var_cantidad;
                    obj_nuevo_movimiento.met_agregar_producto(*var_it, var_cantidad);
                } else {
                    cout << "No hay suficiente cantidad en el inventario." << endl;
                }
            } else {
                cout << "Producto no encontrado en el inventario." << endl;
            }
        }

        vec_historial.push_back(obj_nuevo_movimiento);
        cout << "Venta registrada exitosamente." << endl;
    }

    void met_mostrar_inventario() {
        cout << "Inventario actual:" << endl;
        for (const auto& obj_producto : vec_inventario) {
            obj_producto.met_mostrar_producto(obj_producto.atr_cantidad_producto);
            cout << "--------" << endl;
        }
    }

    void met_mostrar_historial() {
        cout << "Historial de movimientos:" << endl;
        for (const auto& obj_movimiento : vec_historial) {
            obj_movimiento.met_mostrar_movimiento();
            cout << "========" << endl;
        }
    }

private:
    vector<class_producto>::iterator met_buscar_producto(const string& var_codigo) {
        return find_if(vec_inventario.begin(), vec_inventario.end(), [var_codigo](const class_producto& obj_p) {
            return obj_p.atr_codigo_producto == var_codigo;
        });
    }
};

class class_inicio {
private:
    int atr_inicio;
public:
    class_inicio(int var_inicio) {
        atr_inicio = var_inicio;
    }
    void met_iniciar_programa() {
        class_gestion obj_inventario;

        while (atr_inicio == 0) {
            cout << "\n===== Menu =====\n";
            cout << "1. Registrar compra\n";
            cout << "2. Registrar venta\n";
            cout << "3. Mostrar inventario\n";
            cout << "4. Mostrar historial\n";
            cout << "5. Salir\n";
            cout << "=================\n";

            int var_opcion;
            cout << "Seleccione una opción: ";
            cin >> var_opcion;

            if (var_opcion == 5) {
                cout << "Saliendo del programa..." << endl;
                break;
            }

            switch (var_opcion) {
                case 1:
                    obj_inventario.met_registrar_compra();
                    break;
                case 2:
                    obj_inventario.met_registrar_venta();
                    break;
                case 3:
                    obj_inventario.met_mostrar_inventario();
                    break;
                case 4:
                    obj_inventario.met_mostrar_historial();
                    break;
                case 5:
                    cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                    break;
                default:
                    cout << "Opción no válida. Inténtelo de nuevo." << endl;
            }
        }
    }
};

int main() {
    class_inicio obj_p1(0);
    obj_p1.met_iniciar_programa();

    return 0;
}

