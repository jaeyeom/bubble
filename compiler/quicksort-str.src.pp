exchange(A, i, j)
begin
    tmp := A[i]
    A[i] := A[j]
    A[j] := tmp
    i + 1
end
Partition(A, p, r)
begin
    x := A[r]
    i := p - 1
    j := p
    while j < r
    begin
        if A[j] <= x
        begin
            i := i + 1
            exchange(A, i, j)
        end
        j := j + 1
    end
    exchange(A, i+1, r)
    i + 1
end
Quicksort(A, p, r) 
begin
    if p < r 
    begin
        q := Partition(A, p, r)
        Quicksort(A, p, q - 1)
        Quicksort(A, q + 1, r)
    end
end
main()
begin
    A := ["aaa", "bca", "abb", "aac", "bbb"]
    print A 
    Quicksort(A, 0, 4)
    print A 
    i := 0
end
