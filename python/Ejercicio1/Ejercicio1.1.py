#Promedio de duraciòn
otros_cursos_min = 2.5
otros_cursos_max = 7
otros_cursos_promedio = 4
dalto_curso = 1.5

#Duracion de crudos
crudo_promedio = 5
crudo_dalto = 3.5

#Diferencias de duracion
diferencia_con_min = 100 - dalto_curso / otros_cursos_min *100
diferencia_con_max = 100 - dalto_curso * 1000 // otros_cursos_max / 10 #se hace * 1000 y luego se divide todo por 10 para que de un float con un solo decimal
diferencia_con_promedio = 100 - dalto_curso / otros_cursos_promedio *100
print("-----------------------------")

#Calculando el porcentaje de tiempo vacio
tiempo_vacio_promedio = 100 - otros_cursos_promedio * 1000 // crudo_promedio / 10
tiempo_vacio_dalto = 100 - dalto_curso * 1000 // crudo_dalto / 10
#mostrando el porcentaje de diferencia
print(f"El curso de dalto dura {diferencia_con_min}% menos que el mas rapido")
print(f"El curso de dalto dura {diferencia_con_max}% menos que el mas rapido")
print(f"El curso de dalto dura {diferencia_con_promedio}% menos que el mas rapido")
print("-----------------------------")

#mostrando el porcentaje de tiempo vacio
print(f"El porcentaje de tiempo vacio eliminado de dalto es de {tiempo_vacio_dalto}%")
print(f"El porcentaje de tiempo vacio promedio es de {tiempo_vacio_promedio}%")
print("-----------------------------")

#mostrando diferencias si los cursos duraran 10 horas
print(f"Ver 10 horas de este curso equivale a ver {otros_cursos_promedio * 100 // dalto_curso / 10} horas de otros cursos")
print(f"Ver 10 horas de otros cursos equivale a ver {dalto_curso * 100 // otros_cursos_promedio / 10} horas de este curso")
print("-----------------------------")