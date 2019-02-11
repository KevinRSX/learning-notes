# 3 -- Week3

## 3.1 Role of Variables

| Role                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| Constant/Fixed Value | A variable which is initialized without any calculation and whose value does not change thereafter |
| Stepper              | A variable stepping through values that can be predicted as soon as the succession starts (iterator) |
| Most-recent holder   | A variable holding the latest value encountered in foing through a succession of values (such as a succession of user inputs) |
| Gatherer             | A variable accumulating the effect of individual values in going through a succession of values |
| Transformation       | A variable that always gets its new value from the same calculation from values of other variables (interest = 0.05 * deposits, where interest is the transformation) |
| One-way flag         | A two-valued variable that cannot get its initial value once its value has been changed |
| Temporary            | A variable holding some value for a very short time only     |
| Organizer            | An array which is only used for rearranging its elements after initialization |



Example: Consider the following code

```java
public int randomTotal(int how_many)
{
    int max = 10;
    int sum = 0;
    int[] rand_many = new int[how_many];
    Random random = new Random();
    for (int i = 0; i < how_many; i++)
    {
        rands_array[i] = random.nextInt(max);
        sum = sum + rands_array[i];
    }
    return sum;
}
```

Here,

| Variable    | Role      |
| ----------- | --------- |
| How_many    | constant  |
| sum         | gatherer  |
| Rands_array | organizer |
| i           | Stepper   |



