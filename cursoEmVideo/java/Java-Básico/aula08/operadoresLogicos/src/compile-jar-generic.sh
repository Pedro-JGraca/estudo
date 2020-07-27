#!/bin/bash

#show
echo ""
echo "Esse script é para construir um .jar de um programa java"
echo "Para seu funcionamento por favor coloque o script no diretorio acima da função que contêm a main"
#fim do show


function VerificaDiretorio () {
	echo ""
	
	ls -d */ 1> a.txt
	linhas=0
	achados=0
	for line in $(cat a.txt);do
		linhas=$[$linhas+1];done
	
	for line in $(cat a.txt);do
		if [ "$line" == "$dirMain"  ];then	
			echo -n "o diretorio "
			echo -n $dirMain
			echo " existe"
			SAIDA=2
		
		else
			achados=$[$achados+1]
		fi;done

	if [ $achados -eq $linhas ];then
		echo -n "o diretorio "
		echo -n $dirMain
		echo " nao existe existe"
	fi

	echo ""
	
	rm a.txt
}



function EscolheDiretorio () {
SAIDA=1

while [ $SAIDA -eq 1 ]; do 
	echo "-------------------------------------------------------------------"
	echo ""
	
	echo "Escolha o diretorio da sua função main:"
	echo ""
	echo -n "D: "
	ls -d */
	echo ""
	read dirMain
	VerificaDiretorio
	echo "";done
}

function VerificaMain () {
	
	termJava=0

	if [ $termJava -eq 0 ];then
		if [ $(echo $main | cut -d'.' -f 2) == "java" ];then
			termJava=1
		else
			echo -n "Arquivo "
			echo -n $main
			echo " é sem terminacao .java"
		fi
	fi
	
	if [ $termJava -eq 1 ];then

		ls 1> a.txt
	
		qntdLine=0
		for line in $(cat a.txt);do
			qntdLine=$[$qntdLine+1];done

		qntdElse=0

		for line in $(cat a.txt);do
			if [ "$line" == "$main"  ];then	
		
				echo -n "o arquivo "
				echo -n $main
				echo " existe"
				SAIDA=1
				main=$(echo $main | cut -d'.' -f 1)
			else
				qntdElse=$[$qntdElse+1]
			fi;done
	
		if [ $qntdElse -eq $qntdLine ];then
			echo -n "o arquivo "
			echo -n $main
			echo " nao existe"
		fi
	
		rm a.txt
	fi
	
	
}

function EscolheMain () {
	SAIDA=0
	while [ $SAIDA -eq 0 ];do
		echo "-------------------------------------------------------------------"
		echo "Diga qual dos arquivos abaixo é a sua função main:"
		echo ""
	
		echo -n "A: "
		ls
	
		echo ""
		read main

		echo ""
	
		VerificaMain;done
	
	cd ..
}


#main

EscolheDiretorio
cd $dirMain
EscolheMain



#fixas
manifest="Main-Class: "
jar=".jar"
class="*.class"
java=".java"


touch Manifest.txt
echo $manifest$dirMain$main 1>Manifest.txt

javac -d compilado/ $dirMain$main$java 2>a.txt
erroC=$(echo $?)
rm a.txt

if [ $erroC -eq 0 ]; then	
	cd compilado/
	
	jar cfm $main$jar ../Manifest.txt $dirMain$class 2>a.txt
	erroJar=$(echo $?)
	rm a.txt
	
	if [ $erroJar -eq 0 ];then 

		mv $main$jar ../
		cd ../
		
		rm -rf compilado/
		rm Manifest.txt
		chmod +x $main$jar
		echo "foi possivel"
		echo ""
	
	else
			
		echo "nao foi possiver construir o Executavel .jar"
		echo ""
		cd ../
		rm -rf compilado/
		rm Manifest.txt
		rm $main$jar 2>a.txt
		rm a.txt
	fi

else
	
	echo "nao foi possivel compilar .class"
	echo ""
	rm -rf compilado/ 2>>a.txt
	rm a.txt

fi;




