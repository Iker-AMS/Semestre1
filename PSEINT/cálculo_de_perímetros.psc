Algoritmo Cálculo_de_perímetros
	
	Definir opcion Como Entero
	Definir lado, radio, perimetro Como Real
	
	Escribir "Selecciona una opción:"
	Escribir "1. Cuadrado"
	Escribir "2. Triangulo equilatero"
	Escribir "3. Circulo"
	Leer opcion
	
	Segun opcion Hacer
		1:
			Escribir "Elegiste cuadrado, escriba cuanto mide un lado"
			Leer lado
			perimetro = lado * 4
			Escribir "El perímetro de tu cuadrado es:", perimetro
			
		2:
			Escribir "Elegiste triangulo equilatero, escriba cuanto mide un lado"
			Leer lado
			perimetro = lado * 3
			Escribir "El perímetro de tu triangulo equilatero es:", perimetro
			
		3:
			Escribir "Elegiste circulo, escriba cuanto mide el radio"
			Leer radio
			perimetro = 2 * 3.1416 * radio
			Escribir "El perímetro de tu circulo es:", perimetro
			
		De Otro Modo:
			Escribir "Error, opción no válida"
	Fin Segun
	
FinAlgoritmo
