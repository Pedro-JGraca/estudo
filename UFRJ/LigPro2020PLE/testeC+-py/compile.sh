
main="fibonacci"

if [ "$1" == "clean-objects" ]; then
    rm *.o 2>>a.txt
    rm a.txt
elif [ "$1" == "clean-exec" ]; then
    rm $main 2>>a.txt
    rm a.txt
elif [ "$1" == "clean-all" ]; then
    rm *.o $main 2>>a.txt
    rm a.txt
else
    g++ -g -o $main main.cpp  -I/usr/include/python3.8 -lpython3.8
fi