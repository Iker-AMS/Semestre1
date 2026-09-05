Algoritmo salario_por_horas
	
	Definir name Como Caracter
	Definir horas, tarifa, salario Como Real
	
	Escribir "Ingrese su nombre completo";
	Leer name
	Escribir "Ingrese el número de horas trabajadas";
	Leer horas
	Escribir "Ingrese la tarifa de paga por hora";
	Leer tarifa
	
	salario = horas * tarifa
	
	Escribir "Nombre:", name
	Escribir "Horas trabajadas:", horas
	Escribir "Tarifa por hora: $", tarifa
	Escribir "Su salario es de: $", salario 
	
FinAlgoritmo
