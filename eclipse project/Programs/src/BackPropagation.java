import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class BackPropagation {
    public static void main(String[] args) {
        int i, j, numberOfInputNeurons, numberOfHiddeNeurons, numberOfOutputNeurons, rowsInEachSet;
        int[][] input, target;
        float bias, learningRate;
        long epoch;
        try (Scanner in = new Scanner(System.in)) {
            System.out.println("NOTE : Activation Function used is Bipolar Sigmoidal\n");

            System.out.println("Enter the number of neurons at input layer : ");
            numberOfInputNeurons = in.nextInt();

            System.out.println("Enter the number of neurons at hidden layer : ");
            numberOfHiddeNeurons = in.nextInt();

            System.out.println("Enter the number of neurons at output layer : ");
            numberOfOutputNeurons = in.nextInt();

            System.out.println("Enter the number of rows in training data : ");
            rowsInEachSet = in.nextInt();

            System.out.println("Enter the initial bias value for all the neurons \n(This bias " +
                    "value will be same for all the neurons but its weight will change) : ");
            bias = in.nextFloat();

            System.out.println("Enter the learning rate (alpha) : ");
            learningRate = in.nextFloat();

            System.out.println("For how many epoch you want to train network? : ");
            epoch = in.nextInt();

            input = new int[rowsInEachSet][numberOfInputNeurons];
            target = new int[rowsInEachSet][numberOfOutputNeurons];

            System.out.println("NOTE : PLEASE ENTER THE INPUTS IN BIPOLAR FORMAT !!");

            //taking input
            for (i = 0; i < rowsInEachSet; i++) {
                System.out.println("Enter the input value of " + (i + 1) + " row : ");
                for (j = 0; j < numberOfInputNeurons; j++) {
                    input[i][j] = in.nextInt();
                }
                System.out.println("Enter the target value for this input : ");
                for (j = 0; j < numberOfOutputNeurons; j++) {
                    target[i][j] = in.nextInt();
                }
            }

            float weightInputHidden[][] = new float[numberOfHiddeNeurons][numberOfInputNeurons + 1];
            float weightHiddenOutput[][] = new float[numberOfOutputNeurons][numberOfHiddeNeurons + 1];
            float weightChangeInputHidden[][] = new float[numberOfHiddeNeurons][numberOfInputNeurons + 1];
            float weightChangeHiddenOutput[][] = new float[numberOfOutputNeurons][numberOfHiddeNeurons + 1];

            //filling weights randomly
            Random gen = new Random();
            for (i = 0; i < numberOfHiddeNeurons; i++) {
                for (j = 0; j < (numberOfInputNeurons + 1); j++) {
                    int sign = gen.nextInt() % 2;
                    float f = gen.nextFloat();
                    if (sign == 0) f = -f;
                    weightInputHidden[i][j] = f;
                }
            }
            for (i = 0; i < numberOfOutputNeurons; i++) {
                for (j = 0; j < (numberOfHiddeNeurons + 1); j++) {
                    int sign = gen.nextInt() % 2;
                    float f = gen.nextFloat();
                    if (sign == 0) f = -f;
                    weightHiddenOutput[i][j] = f;
                }
            }

            int n, s;
            int outputRow = numberOfHiddeNeurons + numberOfOutputNeurons;
            float output[] = new float[outputRow];
            float delta, delta2, temp;
            //training network
            while (epoch > 0) {
                for (int a = 0; a < rowsInEachSet; a++) {
                    //delta2 = 0;
                    temp = 0;
                    Arrays.fill(output, 0);
                    for (i = 0; i < numberOfHiddeNeurons; i++)
                        Arrays.fill(weightChangeInputHidden[i], 0);
                    for (i = 0; i < numberOfOutputNeurons; i++)
                        Arrays.fill(weightChangeHiddenOutput[i], 0);

                    for (n = 0; n < numberOfHiddeNeurons; n++) {
                        output[n] += bias * weightInputHidden[n][0];
                        for (int b = 1; b < (numberOfInputNeurons + 1); b++) {
                            output[n] += input[a][b - 1] * weightInputHidden[n][b];
                        }
                        output[n] = bipolarSigmoidal(output[n]);
                    }
                    for (s = 0; n < output.length; n++, s++) {
                        output[n] += bias * weightHiddenOutput[s][0];
                        for (int b = 1; b < (numberOfHiddeNeurons + 1); b++) {
                            //output[b-1] is input of hidden neurons
                            output[n] += output[b - 1] * weightHiddenOutput[s][b];
                        }
                        output[n] = bipolarSigmoidal(output[n]);

                        delta = (float) (0.5 * (1 + output[n]) * (1 - output[n]));
                        delta *= (target[a][(n - numberOfHiddeNeurons)] - output[n]);

                        weightChangeHiddenOutput[s][0] = learningRate * delta;
                        for (int b = 1; b < (numberOfHiddeNeurons + 1); b++) {
                            weightChangeHiddenOutput[s][b] = learningRate * delta * output[b - 1];
                        }
                        for (int b = 1; b < (numberOfHiddeNeurons + 1); b++) {
                            temp += delta * weightHiddenOutput[s][b];
                        }
                    }

                    for (n = 0; n < numberOfHiddeNeurons; n++) {
                        delta2 = temp * ((float) (0.5 * (1 + output[n]) * (1 - output[n])));

                        weightChangeInputHidden[n][0] = learningRate * delta2;
                        for (int b = 1; b < (numberOfInputNeurons + 1); b++) {
                            weightChangeInputHidden[n][b] = learningRate * delta2 * input[a][b - 1];
                        }
                    }

                    System.out.println("\nChanged weights between input layer and hidden layer " +
                            "for " + (a + 1) + " input :");
                    for (i = 0; i < numberOfHiddeNeurons; i++) {
                        System.out.println("Neuron " + (i + 1));
                        for (j = 0; j < (numberOfInputNeurons + 1); j++) {
                            weightInputHidden[i][j] += weightChangeInputHidden[i][j];
                            System.out.print(weightInputHidden[i][j] + "  ");
                        }
                        System.out.println();
                    }

                    System.out.println("\nChanged weights between hidden layer and output layer " +
                            "for " + (a + 1) + " input :");
                    for (i = 0; i < numberOfOutputNeurons; i++) {
                        System.out.println("Neuron " + (i + 1));
                        for (j = 0; j < (numberOfHiddeNeurons + 1); j++) {
                            weightHiddenOutput[i][j] += weightChangeHiddenOutput[i][j];
                            System.out.print(weightHiddenOutput[i][j] + "  ");
                        }
                        System.out.println();
                    }
                }
                epoch--;
                System.out.println("\n" + epoch + " EPOCH LEFT !!");
            }
            System.out.println("\nTraining completed successfully!!");
            System.out.println("\nTesting phase!!");

            System.out.println("Enter the number of rows for testing network : ");
            int testRows = in.nextInt();
            int testInput[] = new int[numberOfInputNeurons];

            for (i = 0; i < testRows; i++) {
                System.out.println("Enter the testing value of " + (i + 1) + " row : ");
                for (j = 0; j < numberOfInputNeurons; j++) {
                    testInput[j] = in.nextInt();
                }

                Arrays.fill(output, 0);
                for (n = 0; n < numberOfHiddeNeurons; n++) {
                    output[n] += bias * weightInputHidden[n][0];
                    for (int b = 1; b < (numberOfInputNeurons + 1); b++) {
                        output[n] += testInput[b - 1] * weightInputHidden[n][b];
                    }
                    output[n] = bipolarSigmoidal(output[n]);
                }
                for (s = 0; n < output.length; n++, s++) {
                    output[n] += bias * weightHiddenOutput[s][0];
                    for (int b = 1; b < (numberOfHiddeNeurons + 1); b++) {
                        output[n] += output[b - 1] * weightHiddenOutput[s][b];
                    }
                    output[n] = bipolarSigmoidal(output[n]);
                    System.out.println(output[n]);
                }
            }
        }
    }

    static private float bipolarSigmoidal(float num) {
        return (float) ((1 - Math.exp(-num)) / (1 + Math.exp(-num)));
    }
}
