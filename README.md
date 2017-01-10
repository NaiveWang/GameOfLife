# GameOfLife
GameOfLife with openGL,C language
#preface
        English
I come up with this idea with "Cellular Automaton", we also called it Game of Life.
It's a game without interactive,when the starting condition was set,the game start,running in a 2-dimension matrix,we assume that
the dark place represents void,which white dot represent life,not just ordinary life i guess,
it's more generalized:the object,which could move\infuluence each other autonomous,and also have
a lifespan(Anyway,long live the toad,lol).
In this game , we perceive the 2D matrix as the universe which our "white dot" lives in.It could modify by player(just watch it)
in these attributes:
1.the size you see in screen
2.the edge attribute:could a life staff move out? Or just like our god damn GFW,block it?
Now lets talk about the write dot staff.
It's worth saying that we just modify it at the life process's beginning,all we can do,is to make differences at:
1.initial state,the arrangement of\how much dots
2.the rules during game:how to live,how to die,how to xu.
When playing the game,player plays role in god,says the poem:G L G J S S Y , Q Y H F B Q Z...
2017/1/10 NaiveWang Yantai


        中文
实际上，“生命游戏”这个点子来源于一个逼格更高的名字：元细胞自动机，这玩意是个游戏，游戏的界面是个二维的矩阵，
里面的黑色部分相当于真空，白色小点相当于生命体。这里所说的生命体并不是常规意义上的生命体，它更加广义：
这个东西能够自发的移动，并且互相影响，我们就称这玩意儿是生命。当然啦，它也必须具有自己的生命周期（我为长者续一秒蛤蛤）
我们假设游戏中的矩阵，就是生命体（小白点）所存在的宇宙，那么矩阵应具备哪些可修改的属性呢？有二：
1.大小，实际上通俗意义上讲这玩儿就是在你屏幕上的显示大小
2.边界属性：生命体能从边界穿过么？还是跟中国的墙一样？
下面一提生命体的属性，其中值得注意的是，游戏过程中玩家是不允许参与生命过程的，但是可以在起初修改这些：
1.生命体的初始化状态：多少点啦，咋排列啦之类
2.规则：如何生，如何死，如何续命
于是乎，在玩游戏的时候，玩家扮演上帝角色，嘴里嘟念着：我说另请高明吧，我一个屁民怎么就当上帝了呢，所以我就念了两句诗：苟。
2017年一月十号 烟台

I use C language to run it,with OpenGL.
Let's wait and see，
闷声大发财。
