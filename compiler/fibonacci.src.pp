Fibonacci(i)
begin
        if i <= 2 
        begin
                r := i
        end
        else
        begin
                r := Fibonacci(i - 1) + Fibonacci(i - 2)
        end
        r
end
main()
begin
        print Fibonacci(10)
end
