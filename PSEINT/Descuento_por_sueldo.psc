Algoritmo Descuento_por_sueldo
	Definir sueldo, descuento, sueldo_neto Como Real
	
	Escribir "Escriba su sueldo actual"
	Leer sueldo
	
	Si sueldo <= 1000 Entonces
		descuento = sueldo * .10
	SiNo
		si sueldo <= 2000
			descuento = 1000 * .10 + (sueldo - 1000) * .05
		SiNo
			descuento = 1000 * .10 + 1000 * .5 + (sueldo - 2000) * .03
		FinSi
	Fin Si
	
	sueldo_neto = sueldo - descuento
	Escribir "Su descuento es de: ", descuento
	Escribir "Su sueldo es de: ", sueldo_neto
FinAlgoritmo
