#pragma once
#include <mysql_c_pr.h>
#include <iostream>
#include "Conexion.h"
using namespace  std;
class Marca {
	// atributos
private: string marca;
	   // constructor
public:
	Marca() {}
	Marca(string mr) {
		marca = mr;
	}
	void setMarca(string mr) { marca = mr; }
	string getMarca() { return marca; }

	void crear() {
		int q_estado;
		Conexion cn = Conexion();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos(producto) VALUES ('" + marca + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		Conexion cn = Conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de las Marcas ------------" << endl;
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();


	}
};