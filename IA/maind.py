import numpy as np
import time


GRID_SIZE = 4
NUM_STATES = 16

TERMINAL_STATES = [0, 15]

ACTIONS = [0, 1, 2, 3]
ACTION_NAMES = {0: '↑', 1: '→', 2: '↓', 3: '←'}

REWARD = -1.0
GAMMAS = [1.0, 0.9, 0.8]
THETA = 1e-4 


def get_next_state(state, action):
    """
    Calculates the next state given the current state and action.
    Handles boundary conditions (bumping into a wall).
    """
    if state in TERMINAL_STATES:
        return state

    row, col = state // GRID_SIZE, state % GRID_SIZE
    
    if action == 0: 
        next_row = row - 1
        next_col = col
    elif action == 1:  # RIGHT
        next_row = row
        next_col = col + 1
    elif action == 2:  # DOWN
        next_row = row + 1
        next_col = col
    elif action == 3:  # LEFT
        next_row = row
        next_col = col - 1
    else:
        raise ValueError("Invalid action")


    if (next_row < 0 or next_row >= GRID_SIZE or
        next_col < 0 or next_col >= GRID_SIZE):

        return state
    return next_row * GRID_SIZE + next_col

def print_grid(values, title):
    """Prints a 4x4 grid of values."""
    print(title)
    grid = values.reshape((GRID_SIZE, GRID_SIZE))
    for row in grid:
        print("  ".join(f"{val:6.2f}" for val in row))
    print("-" * 30)

def print_policy(policy, title):
    """Prints a 4x4 grid of policy actions."""
    print(title)
    policy_grid = []
    for i, action in enumerate(policy):
        if i in TERMINAL_STATES:
            policy_grid.append("GOAL")
        else:
            policy_grid.append(ACTION_NAMES[action])
    
    grid = np.array(policy_grid).reshape((GRID_SIZE, GRID_SIZE))
    for row in grid:
        print("  ".join(f"{val:^6}" for val in row))
    print("-" * 30)


def value_iteration(gamma):
    """
    Performs Value Iteration.
    
    This algorithm finds the optimal value function V*(s) by iteratively
    applying the Bellman optimality equation:
    V(s) = max_a [ R + gamma * V(s') ]
    """

    V = np.zeros(NUM_STATES)
    
    while True:
        delta = 0
        V_old = V.copy()
        
        for s in range(NUM_STATES):
            if s in TERMINAL_STATES:
                V[s] = 0 
                continue

            q_values = []
            for a in ACTIONS:
                next_s = get_next_state(s, a)
                q_value = REWARD + gamma * V_old[next_s]
                q_values.append(q_value)
            
            V[s] = max(q_values)
            
            delta = max(delta, abs(V[s] - V_old[s]))
            
        if delta < THETA:
            break
            
    policy = np.zeros(NUM_STATES, dtype=int)
    for s in range(NUM_STATES):
        if s in TERMINAL_STATES:
            policy[s] = -1 
            continue
            
        q_values = []
        for a in ACTIONS:
            next_s = get_next_state(s, a)
            q_value = REWARD + gamma * V[next_s]
            q_values.append(q_value)
        
        policy[s] = np.argmax(q_values)
        
    return V, policy


def policy_evaluation(policy, V_in, gamma):
    """
    Performs Policy Evaluation.
    
    Given a fixed policy pi, this function computes the value function V_pi(s)
    by iteratively applying the Bellman equation for a fixed policy:
    V(s) = R + gamma * V(s')
    """
    V = V_in.copy()
    
    while True:
        delta = 0
        V_old = V.copy()
        
        for s in range(NUM_STATES):
            if s in TERMINAL_STATES:
                V[s] = 0
                continue
            
            a = policy[s]
            

            next_s = get_next_state(s, a)
            V[s] = REWARD + gamma * V_old[next_s]
            
            delta = max(delta, abs(V[s] - V_old[s]))
            
        if delta < THETA:
            break
    return V

def policy_improvement(V, gamma):
    """
    Performs Policy Improvement.
    
    Given a value function V, this function finds a new (and better)
    policy by acting greedily with respect to V.
    """
    policy = np.zeros(NUM_STATES, dtype=int)
    policy_stable = True
    
    for s in range(NUM_STATES):
        if s in TERMINAL_STATES:
            policy[s] = -1
            continue
            
        q_values = []
        for a in ACTIONS:
            next_s = get_next_state(s, a)
            q_value = REWARD + gamma * V[next_s]
            q_values.append(q_value)
        
        new_action = np.argmax(q_values)
        policy[s] = new_action
        
    return policy

def policy_iteration(gamma):
    """
    Performs Policy Iteration.
    
    This algorithm alternates between Policy Evaluation and Policy Improvement
    until the policy no longer changes (it becomes "stable").
    """

    V = np.zeros(NUM_STATES)
    policy = np.zeros(NUM_STATES, dtype=int) 
    
    while True:
        V = policy_evaluation(policy, V, gamma)
        
        new_policy = policy_improvement(V, gamma)
        
        if np.array_equal(policy, new_policy):
            break
            
        policy = new_policy
        
    return V, policy


if __name__ == "__main__":
    for gamma in GAMMAS:
        print(f"\n{'='*10} RUNNING FOR GAMMA = {gamma} {'='*10}\n")
        
        print("Running Value Iteration...")
        start_vi = time.time()
        V_vi, policy_vi = value_iteration(gamma)
        end_vi = time.time()
        print(f"Value Iteration finished in {end_vi - start_vi:.4f} seconds.")
        
        print_grid(V_vi, f"Optimal Value Function (VI, γ={gamma})")
        print_policy(policy_vi, f"Optimal Policy (VI, γ={gamma})")

        print("Running Policy Iteration...")
        start_pi = time.time()
        V_pi, policy_pi = policy_iteration(gamma)
        end_pi = time.time()
        print(f"Policy Iteration finished in {end_pi - start_pi:.4f} seconds.")
        
        print_grid(V_pi, f"Optimal Value Function (PI, γ={gamma})")
        print_policy(policy_pi, f"Optimal Policy (PI, γ={gamma})")

        if np.allclose(V_vi, V_pi) and np.array_equal(policy_vi, policy_pi):
            print(f"SUCCESS: VI and PI results match for γ={gamma}.\n")
        else:
            print(f"FAILURE: VI and PI results DO NOT match for γ={gamma}.\n")