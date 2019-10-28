# Fillit

Fillit is a project that let you discover and/or familiarize yourself with a recurring problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing. In this particular project, you will have to find a way to assemble a given Tetriminos set altogether in the smallest possible square.

## How to run it


```
git clone https://github.com/barthelemyleveque/Fillit.git
cd Fillit
make
```

```./fillit``` will get you the usage :

![Usage](https://i.ibb.co/VV4Vs12/Screen-Shot-2019-10-28-at-11-08-48-AM.png)


The ```txt``` file is an example of a series of tetriminos (there are actually 12 in this example). 

```
....
....
####
....

....
..#.
..##
...#

..........

....
....
#...
###.

....
..#.
..##
..#.
```

* The first tetrimino will be translated as :
```
....
....
AAAA
....
```
* The second tetrimino as :
```
....
..B.
..BB
...B`
```

So when you execute the program with this txt file, the smallest possible square will be :

```./fillit txt ```

![Program](https://i.ibb.co/CKCd0fG/Screen-Shot-2019-10-28-at-11-15-22-AM.png)

It is a recursive problem, with an exponential time complexity when adding more tetriminos.
