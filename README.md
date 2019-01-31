Este programa lo hice para practicar tomando como guia estas instrucciones:

Se trataría de crear un formulario donde se tendrá que introducir un texto.

Tendremos que seleccionar un fichero de texto de entrada que contentrá simplemente una lista de url's o bien, escribir la url directamente en la entrada.

Dar de alta 2 ficheros de salida con los nombre que especifique el usuario y el camino de los mismos.

Se darán dos botones en formulario, uno de Buscar y otro de Cancelar.

Al pichar en Buscar, se desarrollaria el tratamiento siguiente :
Se leera el primer registro del fichero de entrada.
Se accederá a la dirección de la url y se extraerá o descargará a un archivo del mismo nombre que la url leída y en formato html dicha web, (mismo efecto que el botón derecho sobre una web y seleccionando la opción-- Ver código fuente de la página.)
Seguidamente, se abrirá este archivo html y se comprobará en esta si existe o no el texto a buscar que hemos introducido anteriormente. Si se encuentra, esta url del fichero de entrada se grabará en el de salida que el usuario a asignado. Si no se encuentra este texto, la url del fichero de entrada se grabará en el otro fichero designado anteriormente por el usuario.
Una vez completado este procedimiento, leeremos el siguiente registro/url del fichero de entrada y repetiremos la operación. Asi hasta fina de fichero de entrada.
