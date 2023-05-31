# Utilizza un'immagine di base contenente il compilatore C++ e le dipendenze necessarie
 FROM gcc:latest

# # Copia i file del progetto nella directory di lavoro dell'immagine
 COPY . /googletest/samples/

# # Imposta la directory di lavoro
 WORKDIR /googletest/samples/

# # Installa eventuali dipendenze necessarie per il tuo progetto
 RUN apt-get update && apt-get install -y nome_dipendenza 

# # Compila il codice sorgente
# RUN g++ -o my_program main.cpp

# # Specifica l'eseguibile predefinito da avviare quando il container viene eseguito
 CMD ["./samples.exe"] 
