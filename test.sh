#!/bin/bash

echo -e '\033[0mTesting validity a hundred times in a range from 0 to 4'
ERR=0
for i in range {1..99}
	do
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
			echo $ARG
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi


echo -e '\033[0mTesting number of moves a hundred times in a range of 5'
ERR=0
for i in range {1..99}
	do
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l`
		if [ $RET -gt 12 ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi


echo -e '\033[0mTesting a hundred times in a range from -50 to 49'
ERR=0
for i in range {1..99}
	do
		ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi

echo -e '\033[0mTesting number of moves a hundred times in a range of 100 '
ERR=0
for i in range {1..99}
	do
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l`
		if [ $RET -gt 700 ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi


echo -e '\033[0mGetting an average in a range of 100'
ERR=0
for i in range {1..99}
	do
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res

echo -e '\033[0mTesting a hundred times in a range from -250 to 249'
ERR=0
for i in range {1..99}
	do
		ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi

if [ -e "./res" ]
	then
	echo "\033[0merasing res file"
	rm res
fi

echo -e '\033[0mTesting number of moves a hundred times in a range of 500 '
ERR=0
for i in range {1..99}
	do
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l`
		if [ $RET -gt 5300 ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi




rm res
echo -e '\033[0mGetting an average in a range of 500'
ERR=0
for i in range {1..99}
	do
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res
