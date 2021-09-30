//  Author: Kamthorn Krairaksa
//  Github: https://github.com/kamthorn
//
uses	sha1;

var
	msg: string;
	i: int64;

const
	rounds: int64 = 5555555555;

begin
	msg := 'clubhouse';
	for i := 1 to rounds do
	begin
		msg := SHA1Print(SHA1String(msg));
	end;
	writeln(msg);
end.
