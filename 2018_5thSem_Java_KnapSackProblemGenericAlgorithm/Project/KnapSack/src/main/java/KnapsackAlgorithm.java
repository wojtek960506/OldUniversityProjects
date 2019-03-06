import java.util.*;
import java.util.List;


public class KnapsackAlgorithm {

    public Population processAlgorithm(Population population, List<Item> items, int capacityOfKnapsack) {

        fitnessCalcAll(population.getChromosomeList(), items, capacityOfKnapsack);

        if (!population.ifMostHaveSameValue()) {
            Population groupTemp = groupSelection(population);
            Population crossoverTemp = crossoverChromosomes(groupTemp, items, capacityOfKnapsack);
            Population mutateTemp = mutateChromosomes(crossoverTemp, items, capacityOfKnapsack);
            return mutateTemp;
        } else
            return population;
    }

    public void fitnessCalcAll(List<Chromosome> chromosomes, List<Item> items, int capacityOfKnapsack) {
        for (Chromosome chromosome : chromosomes) {
            chromosome.fitnessCalculate(items, capacityOfKnapsack);
        }
    }

    public Population groupSelection(Population population) {
        List<Chromosome> chrGroupPopulation = new ArrayList<>(population.getChromosomeList());
        Collections.sort(chrGroupPopulation, new ChromosomeComparator());
        List<Chromosome> chrCrossOverPopulation = new ArrayList<>();
        int randomChromosomeIndex;
        Random rand = new Random();

        for (int i = 0; i < population.getPopulationSize(); i++) {
            int randomNumber = rand.nextInt(99) + 1;
            Chromosome chosenChromosome;

            if (randomNumber >= 1 && randomNumber < 50) {

                randomChromosomeIndex = rand.nextInt(chrGroupPopulation.size() / 4);
                chosenChromosome = chrGroupPopulation.get(randomChromosomeIndex);


            } else if (randomNumber >= 50 && randomNumber < 80) {

                randomChromosomeIndex = rand.nextInt((chrGroupPopulation.size() / 2) - chrGroupPopulation.size() / 4) + chrGroupPopulation.size() / 4;
                chosenChromosome = chrGroupPopulation.get(randomChromosomeIndex);


            } else if (randomNumber >= 80 && randomNumber < 95) {
                randomChromosomeIndex = rand.nextInt((chrGroupPopulation.size()) - 3 * chrGroupPopulation.size() / 4) + chrGroupPopulation.size() / 2;
                chosenChromosome = chrGroupPopulation.get(randomChromosomeIndex);

            } else {

                randomChromosomeIndex = rand.nextInt(chrGroupPopulation.size() - 3 * chrGroupPopulation.size() / 4) + 3 * chrGroupPopulation.size() / 4;
                chosenChromosome = chrGroupPopulation.get(randomChromosomeIndex);


            }
            chrCrossOverPopulation.add(chosenChromosome);
        }
        return new Population(chrCrossOverPopulation.size(), chrCrossOverPopulation);
    }

    private void mutateChromosome(Chromosome chromosome, List<Item> items, int capacityOfKnapsack) {
        chromosome.setMutateGene(items);
        chromosome.fitnessCalculate(items, capacityOfKnapsack);
    }

    //potem zmien na private
    public Population mutateChromosomes(Population population, List<Item> items, int capacityOfKnapsack) {
        Random rand = new Random();

        List<Chromosome> newMutatePopulation = new ArrayList<>(population.getChromosomeList());

        for (int i = 0; i < newMutatePopulation.size(); i++) {

            //tutaj bylo 999 i 500

            int n = rand.nextInt(99);
            if (n == 5)
                mutateChromosome(newMutatePopulation.get(i), items, capacityOfKnapsack);
        }
        return new Population(newMutatePopulation.size(), newMutatePopulation);
    }

    public Population crossoverChromosomes(Population population, List<Item> items, int capacityOfKnapsack) {
        Random rand = new Random();
        List<Chromosome> chromosomeList = new ArrayList<>(population.getChromosomeList());

        int genesLength = population.getChromosomeList().get(0).getGenes().length;

        ArrayList<Chromosome> newCrossoverPopulation = new ArrayList<>(population.twoBestChromosomes());

        for (int j = 0; j < population.getPopulationSize() / 2 - 1; j++) {

            int firstChrIndex = rand.nextInt(population.getPopulationSize() - 1);
            int secondChrIndex = rand.nextInt(population.getPopulationSize() - 1);
            int d = rand.nextInt(genesLength);
            Chromosome firstChr = chromosomeList.get(firstChrIndex);
            Chromosome secondChr = chromosomeList.get(secondChrIndex);
            int newGenes1[] = new int[genesLength];
            int newGenes2[] = new int[genesLength];

            for (int i = 0; i < genesLength; i++) {
                if (i < d) {
                    newGenes1[i] = firstChr.getGenes()[i];
                    newGenes2[i] = secondChr.getGenes()[i];
                } else {
                    newGenes1[i] = secondChr.getGenes()[i];
                    newGenes2[i] = firstChr.getGenes()[i];
                }
            }
            Chromosome chr1 = new Chromosome(genesLength, newGenes1);
            Chromosome chr2 = new Chromosome(genesLength, newGenes2);
            chr1.fitnessCalculate(items, capacityOfKnapsack);
            chr2.fitnessCalculate(items, capacityOfKnapsack);
            newCrossoverPopulation.add(chr1);
            newCrossoverPopulation.add(chr2);
        }
        return new Population(newCrossoverPopulation.size(), newCrossoverPopulation);
    }
}
