for i in `ls /`;{
  if [ -f $i ];then
    echo $i 是文件;
  else
    echo $i 是目录;
  fi;
}
