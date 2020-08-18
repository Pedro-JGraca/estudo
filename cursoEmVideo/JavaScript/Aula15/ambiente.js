const num = [5,8,2,9,3];

num.push(6);
num.push(num.length);
console.log(num);
num.sort();
//num=2   se num é declarado com let, funciona, se const, não.
console.log(num);

for (let i=0;i <num.length;i++) {
    console.log("A posicao " + i + " tem o valor:" + num[i]);
}
//ou
for (let a in num) {
    console.log("A posicao " + a + " tem o valor:" + num[a]);
}

console.log("O 6 esta na posicao " + num.indexOf(6) ); 