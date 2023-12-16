#le pedimos al usuario que nos diga una frase (o varias)
frase = input("Decime una frase y te calculo cuanto tardarìas si tuvieras que decirla: ")

#creamos una lista con todas las palabras de la frase (se separan cada vez que haya un espacio en blanco)
palabras_separadas = frase.split (" ")
cantidad_de_palabras = len(palabras_separadas)
print(f"Dijiste {cantidad_de_palabras} palabras, tardarias {cantidad_de_palabras / 2} segundos en decirlo")
print(f"Dalto lo diria en {cantidad_de_palabras *100 // 2 * 0.7 / 100} segundos")
if cantidad_de_palabras > 5 :
    print("Para flaco hablas una banda")

 