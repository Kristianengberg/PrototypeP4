s= serial('COM6');

fopen(s);
fprintf('reading serial port 6')
inputdata= fread(s,1);
fprintf('read %d',inputdata)
fclose(s);