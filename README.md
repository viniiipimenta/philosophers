<h1 align="center">Philosophers</h1>
<p>Solving the famous Dining Philosophers problem and discover concurrent programming by using threads and mutexes</p>

---

## Install

```sh
git clone https://github.com/viniiipimenta/philosophers philosophers
```

## Usage

1. Run `make` to compile program

2. Run the program passing the params 

```
./philo num_of_philo time_to_die time_to_eat time_to_sleep num_times_must_eat
```

### Examples
```js
./philo 1 200 200 200 // Not have enough forks, so return error
./philo 2 800 200 200 // Nobody dies
./philo 5 800 200 200 // Nobody dies
./philo 5 800 200 200 7 // Simulation stops when all philosophers eat 7 times
./philo 4 410 200 200 // Nobody dies
./philo 4 310 200 200 // One philosopher dies
./philo 4 500 200 1.2 // Invalid arguments
./philo 4 0 200 200 // Invalid arguments
./philo 4 -500 200 200 // Invalid arguments
./philo 4 500 200 2147483647 // One philopher dies after 500ms
./philo 4 2147483647 200 200 // Nobody dies
./philo 4 214748364732 200 200 // Invalid arguments
./philo 4 200 210 200 // One philosopher dies, you should show his dead before 210ms
```
