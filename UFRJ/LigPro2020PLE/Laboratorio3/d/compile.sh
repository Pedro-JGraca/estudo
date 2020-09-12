principal="agenda"

if [ "$1" == "clean-objects" ]; then
    rm *.o 2>>a.txt
    rm a.txt
elif [ "$1" == "clean-exec" ]; then
    rm $principal 2>>a.txt
    rm a.txt
elif [ "$1" == "clean-all" ]; then
    rm *.o $principal 2>>a.txt
    rm a.txt
else
    g++ -Wall -c main.cpp -o principal.o
    g++ -Wall -c $principal.cpp -o $principal.o
    g++ -Wall *.o -o $principal
    if [ "$1" == "compile" ]; then
        rm *.o 2>>a.txt
        rm a.txt
    fi
fi

