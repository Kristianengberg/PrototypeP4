s= serial('COM6');
f = gcf;
i= 1;
key = 0;
[clay,FsC] = audioread('clay.mp3');
[stone,FsS] = audioread('stone.wav');
[gold,FsG] = audioread('gold.wav');
[wood,FsW] = audioread('wood.mp3');
[paper,FsP] = audioread('paper.mp3');
[loom,FsL] = audioread('loom.wav');
[glass,FsGl] = audioread('glass.wav');
[market,FsM] = audioread('market.wav');
[war,FsWa] = audioread('war.wav');
[research,FsR] = audioread('research.wav');
[civilian,FsCi] = audioread('civilian.wav');
[camel,FsCa] = audioread('camel.wav');

fopen(s);
while i == 1
key=double(get(f,'CurrentCharacter')) ;
if key == 31
    i = 0;
end

inputdata= fread(s,1);
if(inputdata ~= 0)
fprintf(' read %d',inputdata)
end
if(inputdata == 8)
    sound(clay,FsC);
end
if(inputdata == 7)
    sound(stone,FsS);
end
if(inputdata == 6)
    sound(wood,FsW);
end
if(inputdata == 5)
    sound(gold,FsG);
end
if(inputdata == 3)
    sound(glass,FsGl);
end
if(inputdata == 2)
    sound(paper,FsP);
end
if(inputdata == 4)
    sound(loom,FsL);
end
if(inputdata == 9)
    sound(war,FsWa);
end
if(inputdata == 10)
    sound(market,FsM);
end
if(inputdata == 13)
    sound(research,FsR);
end
if(inputdata == 12)
    sound(civilian,FsCi);
end
if(inputdata == 11)
    sound(camel,FsCa);
end
pause(.0001);
end
fclose(s);
fprintf(' code done')