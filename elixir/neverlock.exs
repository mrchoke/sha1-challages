defmodule Loop do
	def sha_multiple_times(msg,n) when n <= 2 do
		IO.puts :crypto.hash(:sha,msg) |> Base.encode16() |> String.downcase()
	end

	def sha_multiple_times(msg,n) do
		data = :crypto.hash(:sha,msg)
		sha_multiple_times(data |> Base.encode16() |> String.downcase(),n-1)
	end
end


data = :crypto.hash(:sha,"clubhouse")
#IO.puts data |> Base.encode16() |> String.downcase()
Loop.sha_multiple_times(data|>Base.encode16() |> String.downcase(),5555555555)
