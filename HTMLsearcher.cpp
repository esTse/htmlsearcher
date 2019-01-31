#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <cstring>
using namespace std;

string fich_entrada,fich_salida1,fich_salida2;

void create();
void buscar_clasificar(string name,string palabra,string fichero_salida1, string fichero_salida2, string url);


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}



int main()
{
	CURL *curl;
  	CURLcode res;
  	string readBuffer;
	string texto,url;

	cout<<"Escriba el texto que desea buscar: ";
	getline(cin,texto);

	create();

	ifstream archivo;

	archivo.open(fich_entrada,ios::in);//abre el archivo para leer las urls
	if(archivo.fail()){
		cout << "No se pudo abrir el archivo " << fich_entrada << endl;
		exit(1);
	}
	
	while(!archivo.eof()){
		getline(archivo,url,'\n');//obtiene las lineas
        cout<<url<<endl;
        
        string str = url;//transforma el string a char para poderselo pasar a curl_easy_setopt
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
    
   	    curl = curl_easy_init();
  		if(curl) {
    		curl_easy_setopt(curl, CURLOPT_URL, cstr);//realiza la peticion a la url
    		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);//funcion escritura de la respuesta en el readbuffer
    		res = curl_easy_perform(curl);
    		curl_easy_cleanup(curl);

    		ofstream archivo1;
			archivo1.open(url + ".html");//crea unarchivo con el nombre de la url no puede ser http://
			if(archivo1.fail()){
				cout << "No se pudo abrir el archivo " << url + ".html" << endl;
				exit(1);
			}
    		archivo1 << readBuffer;
    		archivo1.close();
    		buscar_clasificar(url + ".html", texto, fich_salida1, fich_salida2, url);
    		delete [] cstr;//limpia cadenastr
    		readBuffer.clear();

  		}

  	}
	archivo.close();
		
return 0;	
}
	

void create(){//crea los archivos 
	
	cout << "Ruta del fichero de entrada: ";
	getline(cin,fich_entrada);
	cout << "Nombre del fichero para guardar las URL coincidentes: ";
	getline(cin,fich_salida1);
	cout << "Nombre del fichero para guardar el reso de URL: ";
	getline(cin,fich_salida2); 
	
	ofstream archivo;

	archivo.open(fich_salida1);
	if(archivo.fail()){
		cout << "No se pudo crear el archivo "<< fich_salida1 << endl;
		exit(1);
	}
	archivo.close();

	archivo.open(fich_salida2);
	if(archivo.fail()){
		cout << "No se pudo crear el archivo "<< fich_salida2 << endl;
		exit(1);
	}
	archivo.close();
}


void buscar_clasificar(string name,string palabra,string fichero_salida1, string fichero_salida2, string url){

	string contenido; 
	bool encontrado = false;

	ifstream archivo;
	archivo.open(name,ios::in);
	if(archivo.fail()){
			cout << "No se pudo abrir el archivo" << name << "para realizar la busqueda de coincidencias." << endl;
			exit(1);
	}

	while(!archivo.eof()){//busca la palabra linea por linea
		getline(archivo, contenido, '\n');
		
		if (contenido.find(palabra) != std::string::npos) {
			encontrado = true;//usamos un bool para que no la guarde la url cada vez que la encuentra o no.
    	}
    }

	if(encontrado){
		ofstream archivo1;
		archivo1.open(fichero_salida1,ios::app);
		archivo1 << url << endl;
		archivo1.close();
	}else{
		ofstream archivo1;
		archivo1.open(fichero_salida2,ios::app);
		archivo1 << url << endl;
		archivo1.close();
	}
	archivo.close();
}




