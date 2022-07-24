
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start, dur, end;
    bool operator < (const Workshop& w) const
    {
        return (end < w.end);
    }
};

struct Available_Workshops
{
    int n;
    Workshop* arr;
    Available_Workshops(int p_n)
    {
        n = p_n;
        arr = new Workshop[n];
    }
    ~Available_Workshops()
    {
        delete[] arr;
    }
};

Available_Workshops* initialize(int start_time[], int duration[], int n) 
{
    Available_Workshops* aw_pt = new Available_Workshops(n);
    for(int i = 0; i < n; i++)
    {
        aw_pt->arr[i].start = start_time[i];
        aw_pt->arr[i].dur = duration[i];
        aw_pt->arr[i].end = start_time[i] + duration[i];
    }
    return aw_pt;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    if(ptr->n == 0)
        return 0;
    int count = 1;
    sort(ptr->arr, ptr->arr + ptr->n);
    int cur_end = ptr->arr[0].end;
    for(int i = 1; i < ptr->n; i++)
    {
        if(cur_end <= ptr->arr[i].start)
        {
            cur_end = ptr->arr[i].end;
            count++;
        }
    }
    return count;
}