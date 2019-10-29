#!/bin/bash

#项目简介：图书管理系统，面向图书管理员与读者
#制作者：邱雅颖，胡亦璇，何明捷，谢彤，黎沼兰
#制作时间：2019.03.15

whiptail --title "图书管理系统" --msgbox " 欢迎进入图书管理系统！" 10 60
while true
do
OPTION=$(whiptail --title "菜单" --menu "请输入序号选择您想进行的操作：" 20 60 6 \
"1" "添加书籍" \
"2" "查找书籍" \
"3" "推荐书籍" \
"4" "删除书籍" \
"5" "浏览所有图书目录" \
"6" "退出系统"  3>&1 1>&2 2>&3)
exitstatus=$?
if [ $exitstatus = 0 ]; then
case $OPTION in
1) 
while true
do
bookType=$(whiptail --title "添加书籍" --inputbox "请输入书籍类型CHINA(中国文学)/FOREIGN(外国文学)/SOCIAL(人文社科)：" 10 60  3>&1 1>&2 2>&3)
if [ $? -eq 1 ];then break 1
fi
bookID=$(whiptail --title "添加书籍" --inputbox "请输入书籍ID：" 10 60  3>&1 1>&2 2>&3)
if [ $? -eq 1 ];then break 1
fi
bookName=$(whiptail --title "添加书籍" --inputbox "请输入书籍名称：" 10 60  3>&1 1>&2 2>&3)
if [ $? -eq 1 ];then break 1
fi
author=$(whiptail --title "添加书籍" --inputbox "请输入书籍作者：" 10 60  3>&1 1>&2 2>&3)
if [ $? -eq 1 ];then break 1
fi
bookConcern=$(whiptail --title "添加书籍" --inputbox "请输入书籍出版社：" 10 60  3>&1 1>&2 2>&3)
if [ $? -eq 1 ];then break 1
fi
echo "$bookType       $bookID    $bookName $author $bookConcern" >> book.txt
whiptail --title "图书管理系统" --msgbox "录入成功！" 10 60
whiptail --title "选择" --yesno "是否继续添加?" 10 60
if [ $? -eq 1 ];then break 1
fi
done
;;

2)
while true
do
whiptail --title "查找书籍" --msgbox " 请输入以下五个内容中任意一个： \
1.书籍类型 \
2.书籍ID \
3.书籍名称 \
4.书籍作者 \
5.书籍出版社" 10 60
ser=$(whiptail --title "查找书籍" --inputbox "" 10 60  3>&1 1>&2 2>&3)
cat book.txt | grep $ser >text_textbox
whiptail --scrolltext  --textbox text_textbox 10 60
if [ $? -eq 1 ];then echo "无此书籍"   
fi
whiptail --title "选择" --yesno "是否继续查找?" 10 60
if [ $? -eq 1 ];then break 1
fi
done
;;

3)
OP=$(whiptail --title "推荐书籍" --menu "请输入序号选择您想进行的操作：" 20 60 3 \
"1" "中国文学" \
"2" "外国文学" \
"3" "人文社科"  3>&1 1>&2 2>&3)
case $OP in
1)
whiptail --title "《子夜》" --msgbox " 作者简介: \
茅盾,1896年7月4日—1981年3月27日原名沈德鸿，生于浙江省桐乡市乌镇，作家、文学评论家。茅盾出生于旧社会，但家庭思想观念新颖，从小接受新式教育，1913年考入北京大学预科，毕业后进入商务印书馆工作，是新文化运动的先驱之一。 \
 内容简介: \
《子夜》是我国著名作家茅盾于1931年发表的一部长篇小说，小说以1930年的旧上海为背景，以民族资本家吴荪甫为中心，描写了当时中国社会的各种矛盾和斗争。为我们展现了一幅幅广阔、真实的历史图景，也塑造了一个个值得我们反思的人物形象。而《林家铺子》原名《倒闭》，作于1932年7月。描述了“一·二八事变”前后上海附近的一个小镇上林家小百货商店由挣扎到倒闭的故事。揭示了民族工商业在帝国主义、封建主义、官僚资本主义的三座大山的压迫下只能破产的残酷现实。" 20 60
;;
2)
whiptail --title "《追风筝的人》" --msgbox " 作者简介: \
卡勒德•胡赛尼（Khaled Hosseini），1965年生于阿富汗喀布尔市，后随父亲逃往美国。胡塞尼毕业于加州大学圣地亚哥医学系，现居加州。“立志拂去蒙在阿富汗普通民众面孔的尘灰，将背后灵魂的悸动展示给世人。\
 内容简介: \
12岁的阿富汗富家少爷阿米尔与仆人哈桑情同手足。然而，在一场风筝比赛后，发生了一件悲惨不堪的事，阿米尔为自己的懦弱感到自责和痛苦，逼走了哈桑，不久，自己也跟随父亲逃往美国。
成年后的阿米尔始终无法原谅自己当年对哈桑的背叛。为了赎罪，阿米尔再度踏上暌违二十多年的故乡，希望能为不幸的好友尽最后一点心力，却发现一个惊天谎言，儿时的噩梦再度重演，阿米尔该如何抉择？" 20 60
;;
3)
whiptail --title "《资本论》" --msgbox " 作者简介: \
卡尔•马克思（Karl Marx，1818～1883）生于德国特利尔城，是德国最著名的哲学家、经济学家，马克思主义的创始人。\
内容简介: \
《资本论》是马克思倾其毕生心血写成的一部科学著作。它被奉为工人阶级革命的“圣经”，是一部融哲学、政治经济学、科学社会主义为一体，博大精深的马克思主义百科全书，是人类思想史上不配的理论丰碑。它揭示了现代社会的经济运动规律，对于我们认识资本主义经济和研究社会主义经济提供了基本原理。" 20 60
;;
esac
;;

4)
while true
do
whiptail --title "查找书籍" --msgbox " 请输入以下两个内容中任意一个： \
1.书籍类型 \
2.书籍ID" 10 60
OP4=$(whiptail --title "删除书籍" --inputbox "" 10 60  3>&1 1>&2 2>&3)
if [ $? -eq 1 ];then break 1
fi
sed -e "/$del/d" book.txt > temp
rm -f book.txt
mv temp book.txt
whiptail --title "删除书籍" --msgbox " 删除成功!" 10 60
whiptail --title "选择" --yesno "是否继续删除?" 10 80
if [ $? -eq 1 ];then break 1
fi
done
;;

5)
whiptail --title "浏览所有图书目录" --scrolltext --textbox book.txt 20 80
;;

6)
whiptail --title "退出" --msgbox " 感谢使用!" 10 60
exit
;;

esac
fi
done


