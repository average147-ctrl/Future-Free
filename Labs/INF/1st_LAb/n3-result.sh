echo "Введите имя пользователя"
read NAME
if [[ -n "$NAME" ]] ; then
	echo "Привет, $NAME"
else
	echo "Пожалуйста, укажите свое имя"
fi 
