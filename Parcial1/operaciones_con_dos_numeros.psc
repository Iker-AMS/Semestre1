Algoritmo operaciones_con_dos_numeros
	
	Definir num1, num2, result Como Real
	Escribir "Escriba un número"
	Leer num1
	Escribir "Escriba otro número"
	Leer num2
	
	Si num1 = num2 Entonces
		result = num1 * num2
		Escribir result
	Fin Si
	
	Si num1 > num2 Entonces
		result = num1 - num2
		Escribir result
	Fin Si	
		
	Si num1 < num2 Entonces
		result = num1 + num2
		Escribir result
	Fin Si
	
FinAlgoritmo
