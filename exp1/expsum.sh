echo "For ver."
sum=0
for ((i=1;i<=100;i++)); do
	sum=$((sum + i));
done
echo $sum

echo "While ver."
sum=0
i=1
while [ "$i" -le 100 ]; do
	sum=$((sum + i));
	i=$((i + 1));
done
echo $sum
