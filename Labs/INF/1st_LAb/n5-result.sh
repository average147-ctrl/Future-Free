nc -l 12345
while true; do
{read msg	;
echo "$msg" >>1.txt;
echo "Сообщение получено"; } | nc -l 12345
rm 1.txt
done
