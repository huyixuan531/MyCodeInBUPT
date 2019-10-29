#!/bin/bash

#PROBLEMS:

#there is no certain book!
#recommend books
#TYPE EXPLAIN

echo "欢迎进入图书管理系统！"
while true
do
echo "--------------------------"
echo "|菜单：                         "
echo "|1.添加书籍                    "
echo "|2.查找书籍                    "
echo "|3.推荐书籍              "
echo "|4.删除书籍                    "
echo "|5.浏览所有图书目录            "
echo "|6.退出系统                     "
echo "--------------------------"
echo "请输入序号选择您想进行的操作："
read choose

case $choose in

1)
while true
do
echo "添加书籍："
echo "请输入书籍类型："
echo "输入CHINA(中国文学)/FOREIGN(外国文学)/SOCIAL(人文社科)"
read bookType
echo "请输入书籍ID："
read bookID
echo "请输入书名："
read bookName
echo "请输入书籍出版社："
read bookConcern
echo "请输入作者："
read author
echo "$bookType       $bookID    $bookName $author $bookConcern" >> book.txt
echo "录入成功！"
echo "$bookType       $bookID    $bookName $author $bookConcern" 
echo "---------------------------" 
#
echo "是否继续添加？"
echo "请输入Y或N："
read op1
if [ "$op1"x = "N"x ];then break 1
fi
done
;;

2)
while true
do
echo "查找书籍："
echo "请输入以下五个选项中任意一个："
echo "---------------------------"
echo "|1.书籍类型"
echo "|2.书籍ID"
echo "|3.书籍名称"
echo "|4.书籍作者"
echo "|5.书籍出版社"
echo "---------------------------"
read ser
cat book.txt | grep $ser
#
if [ $? -eq 1 ];then echo "no this book"   
fi
#
echo "是否继续查找？"
echo "请输入Y或N："
read op2
if [ "$op2"x = "N"x ];then break 1
fi
done
;;

3)
echo "请为我推荐书籍"
echo "请输入推荐书籍的类型序号:"
echo "---------------------------"
echo "|1.中国文学"
echo "|2.外国文学"
echo "|3.人文社科"
echo "---------------------------"
read op3
case $op3 in
	1)
	echo "《子夜》"
	echo "作者简介:"
	echo "茅盾"
	echo "1896年7月4日—1981年3月27日"
	echo "原名沈德鸿，生于浙江省桐乡市乌镇，作家、文学评论家。"
	echo "茅盾出生于旧社会，但家庭思想观念新颖，从小接受新式教育，1913年考入北京大学预科，毕业后进入商务印书馆工作，是新文化运动的先驱之一。"
	echo "内容简介:"
	echo "《子夜》是我国著名作家茅盾于1931年发表的一部长篇小说，小说以1930年的旧上海为背景，以民族资本家吴荪甫为中心，描写了当时中国社会的各种矛盾和斗争。为我们展现了一幅幅广阔、真实的历史图景，也塑造了一个个值得我们反思的人物形象。而《林家铺子》原名《倒闭》，作于1932年7月。描述了“一·二八事变”前后上海附近的一个小镇上林家小百货商店由挣扎到倒闭的故事。揭示了民族工商业在帝国主义、封建主义、官僚资本主义的三座大山的压迫下只能破产的残酷现实。"
	;;
	2)
	echo "《追风筝的人》"
	echo "作者简介:"
	echo "卡勒德•胡赛尼（Khaled Hosseini），1965年生于阿富汗喀布尔市，后随父亲逃往美国。胡塞尼毕业于加州大学圣地亚哥医学系，现居加州。“立志拂去蒙在阿富汗普通民众面孔的尘灰，将背后灵魂的悸动展示给世人。"
	echo "内容简介:"
	echo "12岁的阿富汗富家少爷阿米尔与仆人哈桑情同手足。然而，在一场风筝比赛后，发生了一件悲惨不堪的事，阿米尔为自己的懦弱感到自责和痛苦，逼走了哈桑，不久，自己也跟随父亲逃往美国。
成年后的阿米尔始终无法原谅自己当年对哈桑的背叛。为了赎罪，阿米尔再度踏上暌违二十多年的故乡，希望能为不幸的好友尽最后一点心力，却发现一个惊天谎言，儿时的噩梦再度重演，阿米尔该如何抉择？"
	;;
	3)
	echo "《资本论》"
	echo "作者简介:"
	echo "卡尔•马克思（Karl Marx，1818～1883）生于德国特利尔城，是德国最著名的哲学家、经济学家，马克思主义的创始人。"
	echo "内容简介:"
	echo "《资本论》是马克思倾其毕生心血写成的一部科学著作。它被奉为工人阶级革命的“圣经”，是一部融哲学、政治经济学、科学社会主义为一体，博大精深的马克思主义百科全书，是人类思想史上不配的理论丰碑。它揭示了现代社会的经济运动规律，对于我们认识资本主义经济和研究社会主义经济提供了基本原理。"
	;;
esac
;;

4)
while true
do
echo "删除书籍:"
echo "请输入以下两个选项中任意一个："
echo "---------------------------"
echo "|1.书籍ID"
echo "|2.书籍名称"
echo "---------------------------"
read del
sed -e "/$del/d" book.txt > temp
rm -f book.txt
mv temp book.txt
#
echo "删除成功!"
echo "是否继续删除？"
echo "请输入Y或N："
read op4
if [ "$op4"x = "N"x ];then break 1
fi
done
;;

5)
echo "浏览所有图书目录:"
cat book.txt
;;

6)
echo "感谢使用!"
exit
esac

done



