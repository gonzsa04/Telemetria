#include "JsonSerializer.h"


string JsonSerializer::Serialize(int event) {
	//for (GameObject* it : SceneItems) {
	//	it->saveToJson(j);	//manda a todos los objetos guardarse en dichos archivos
	//}
	return toJson(event);
}


string JsonSerializer::toJson(int event) {
	int id = 1;
	string result = "..\\Test\\saves\\Evento" + to_string(id);
	result = result + ".json";

	std::ofstream i(result); //archivo donde se va a guardar
	json j;
	//for que recorra los atributos??
	i << std::setw(3) << j; //pretty identación para leer mejor el archivo
	i.close(); //cierra el flujo
	return result;
}