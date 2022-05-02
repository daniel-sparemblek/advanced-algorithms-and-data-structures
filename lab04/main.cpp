#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>


using namespace std;

double optimize();

double function1(double x, double y);

class Chromosome {
public:
    double x;
    double y;
    double fitness;
};

class GA {
public:
    Chromosome* population = new Chromosome[20];
    void gen_pop();
    double select_chromosomes();
    Chromosome crossover(pair<Chromosome, Chromosome>);
    Chromosome mutate(Chromosome c);
    void print_pop();
};

void GA::gen_pop() {
    for (int i = 0; i < 20; ++i) {
        static default_random_engine generator(unsigned(time(nullptr)));
        uniform_real_distribution<double> distribution(-5, 5);
        population[i].x = distribution(generator);
        population[i].y = distribution(generator);
        population[i].fitness = function1(population[i].x, population[i].y);
    }
}

double GA::select_chromosomes() {
    // Select the two best chromosome and cross their x's and y's and put
    // the child in the place of the worst chromosome
    pair<Chromosome, Chromosome> selection;
    double worst_fitness = population[0].fitness;
    double best_fitness = population[0].fitness;
    double second_best_fitness = population[0].fitness;
    int worst_fitness_index = 0;
    int best_fitness_index = 0;
    int second_best_fitness_index = 0;
    for (int i = 1; i < 20; ++i) {
        if (population[i].fitness < worst_fitness) {
            worst_fitness = population[i].fitness;
            worst_fitness_index = i;
        }
        if(population[i].fitness > best_fitness) {
            second_best_fitness = best_fitness;
            best_fitness = population[i].fitness;
            second_best_fitness_index = best_fitness_index;
            best_fitness_index = i;
        }
    }
    //cout << "Best in this iteration: " << best_fitness << " with index " << best_fitness_index << endl;
    //cout << "Second best in this iteration: " << second_best_fitness << " with index " << second_best_fitness_index << endl;
    //cout << "Worst in this iteration: " << worst_fitness << " with index " << worst_fitness_index << endl;
    int c1 = rand() % 21;
    int c2, c3;
    do {
        c2 = rand() % 21;
    } while (c1 == c2);
    do {
        c3 = rand() % 21;
    } while (c3 == c1 || c3 == c2);
    double worst_fitness_tournament = population[c1].fitness;
    int worst_fitness_tournament_index = c1;
    if (population[c2].fitness < worst_fitness_tournament) {
        worst_fitness_tournament = population[c2].fitness;
        worst_fitness_tournament_index = c2;
    }
    if (population[c3].fitness < worst_fitness_tournament) {
        worst_fitness_tournament = population[c3].fitness;
        worst_fitness_tournament_index = c3;
    }
    if(worst_fitness_tournament_index != c1) {
        selection.first = population[c1];
        if(worst_fitness_tournament_index != c2) {
            selection.second = population[c2];
        } else selection.second = population[c3];
    } else {
        selection.first = population[c2];
        selection.second = population[c3];
    }
    Chromosome child = crossover(selection);
    Chromosome mutated_child = mutate(child);
    mutated_child.fitness = function1(mutated_child.x, mutated_child.y);
    population[worst_fitness_tournament_index] = mutated_child;
    return best_fitness + 0.03;
}

Chromosome GA::crossover(pair<Chromosome, Chromosome> chromopair) {
    Chromosome *child = new Chromosome();
    child->x = (chromopair.first.x + chromopair.second.x) / 2;
    child->y = (chromopair.first.y + chromopair.second.y) / 2;
    return *child;
}

Chromosome GA::mutate(Chromosome c) {
    double tmp = c.x;
    c.x = c.y;
    c.y = tmp;
    return c;
}

void GA::print_pop() {
    for (int i = 0; i < 20; ++i) {
        //cout << "Chromosome " << i+1 << ": x->" << population[i].x << " y->" << population[i].y <<
        //" fitness->" << population[i].fitness << endl;
    }
    //cout << endl;
}

int main() {
    double res = optimize();
    return 0;
}

double optimize() {
    srand(static_cast<unsigned int>(clock()));
    GA *algorithm = new GA();
    algorithm->gen_pop();
    int iteration = 0;
    double best_fitness = 0;
    do {
        iteration++;
        algorithm->print_pop();
        best_fitness = algorithm->select_chromosomes();
    } while (iteration < 300);
    cout << best_fitness;
    return best_fitness;
}

double function1(double x, double y) {
    double brojnik = 7 * x * y;
    double eksponent = pow(x, 2) + pow(y, 2) + x;
    double nazivnik = exp(eksponent);
    double res = brojnik / nazivnik;
    return res;
}
