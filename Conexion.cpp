#pragma once
#include <mysql_c_pr.h>
#include <iostream>
using namespace  std;
class Conexion
{
private:  MYSQL* conectar;
public:
	void abrir_conexion() {

		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empres@123", "db_empresa", 3306, NULL, 0);

	}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrar_conexion() {
		mysql_close(conectar);
	}

};
