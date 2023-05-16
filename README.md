# Coalition Race Simulation

This program simulates the "Coalition Race" in SPLand, a faraway democracy facing a political crisis. The goal is to help the politicians find a coalition by creating a C++ program that performs the simulation.

## Assignment Definition

The assignment requires implementing several classes and their methods to simulate the coalition race. Here is an overview of the main classes and their responsibilities:

1. Parser: Responsible for parsing the JSON configuration file.
2. Simulation: Manages the simulation resources and steps.
3. Graph: Represents the graph with parties as vertices and collaborations as edges.
4. Party: Represents a party in the graph, with properties like id, name, mandates, join policy, and state.
5. Agent: Represents an agent associated with a party, with properties like agentId, partyId, and selection policy.
6. SelectionPolicy: Abstract class representing the strategy for selecting the next party to offer.
7. JoinPolicy: Abstract class representing the strategy for choosing which offer to accept and which coalition to join.

The program flow involves initializing the simulation, stepping through iterations, and checking termination conditions.

## Configuration File Format

The program takes a configuration file in JSON format as input. The file contains information about parties, the graph, and agents. The structure of the configuration file is as follows:

```
{
  "parties": [
    {
      "name": "Party1",
      "mandates": 30,
      "join_policy": "MandatesJoinPolicy"
    },
    {
      "name": "Party2",
      "mandates": 40,
      "join_policy": "LastOfferJoinPolicy"
    },
    ...
  ],
  "graph": [
    [0, 1, 0, 1],
    [1, 0, 1, 0],
    [0, 1, 0, 1],
    [1, 0, 1, 0]
  ],
  "agents": [
    {
      "party_id": 0,
      "selection_policy": "EdgeWeightSelectionPolicy"
    },
    {
      "party_id": 1,
      "selection_policy": "MandatesSelectionPolicy"
    },
    ...
  ]
}
```

## Termination Conditions

The program terminates when one of the coalitions reaches at least 61 mandates or when all parties have joined a coalition.

## Output

The program generates an output file in JSON format, representing the state of the simulation. The output file contains information about the parties, agents, coalitions, and the steps taken during the simulation.

## Usage

To run the program, provide the path to the configuration file as a command-line argument:

```
./coalition_race_simulation config.json
```

## Visualization

A Python script named `visualization.py` is provided to visualize the output file. The script requires the `networkx` and `matplotlib` packages. You can run the script using the following command:

```
python3 visualization.py output.json
```

## Testing

Three JSON files are provided for testing different scenarios of the program. You can compare the expected output with your actual output using the `diff` command in Linux.

```
diff expected_output.json actual_output.json
```

## Notes
- For a full understanding of the project, open file instructions and read the provided file there 
