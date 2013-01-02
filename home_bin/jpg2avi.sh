WEBCAM_DIR="/work/webcam/"
AVIOUT_DIR="/work/webcam/avi/"
RATE=30
#VCODEC=rawvideo
VCODEC=mpeg4
BITRATE=800k
DATE=`date +%Y%m%d_%H%M`

cd $WEBCAM_DIR

mkdir avi 2>/dev/null
mkdir tmp 2>/dev/null

n=0
for i in `ls *.jpg`
do
	newfile=`printf %08d.jpg $n`
	mv $i tmp/$newfile
	n=`expr $n + 1`
done

ffmpeg -i tmp/%08d.jpg -b $BITRATE -s hd720 -aspect 16:9 -f avi -vcodec $VCODEC -r $RATE $AVIOUT_DIR/$DATE.avi

rm -rf tmp
