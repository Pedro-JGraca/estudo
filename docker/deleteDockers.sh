for i in $(seq 2 $1); do
	docker rm -f $(docker ps -a | awk '{print $1}' | awk "{if(NR==${i}) print $3}")
done

for i in $(seq 2 $1); do
	docker rmi -f $(docker images -a | awk '{print $3}' | awk "{if(NR==${i}) print $3}")
done
