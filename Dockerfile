# Utilizza un'immagine di base contenente il compilatore C++ e le dipendenze necessarie
 FROM ubuntu:latest
 
# Expose port :8080
# EXPOSE 8080
 WORKDIR /app
# Copia i file del progetto nella directory di lavoro dell'immagine
 COPY main/main.exe .
 COPY ./main/inputText.txt .
# Imposta la directory di lavoro


# Installa eventuali dipendenze necessarie per il tuo progetto
 RUN apt-get update 
#   && apt-get install -y nome_dipendenza 

# Compila il codice sorgente
# RUN 

# Specifica l'eseguibile predefinito da avviare quando il container viene eseguito
 CMD ["./main.exe","inputText.txt" ,"outText.txt"] 
