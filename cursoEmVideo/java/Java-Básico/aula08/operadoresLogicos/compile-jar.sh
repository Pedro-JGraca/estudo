touch Manifest.txt
echo "Main-Class: operadoresLogicos/TelaIdade" 1>Manifest.txt
cd src/
echo 4
javac -d compilado/ operadoresLogicos/TelaIdade.java
echo 6
cd compilado/
jar cfm TelaIdade.jar ../../Manifest.txt operadoresLogicos/*.class
echo 9
mv TelaIdade.jar ../../
cd ../
rm -rf compilado/
cd ../
rm Manifest.txt
chmod +x TelaIdade.jar
