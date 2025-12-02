import gymnasium as gym
import numpy as np
import matplotlib.pyplot as plt


def update_q_table(Q, s, a, r, sprime, alpha, gamma):
    """
    This function should update the Q function for a given pair of action-state
    following the q-learning algorithm, it takes as input the Q function, the pair action-state,
    the reward, the next state sprime, alpha the learning rate and gamma the discount factor.
    Return the same input Q but updated for the pair s and a.
    """
    # Q-learning update rule: Q(s,a) = Q(s,a) + alpha * (r + gamma * max(Q(s',a')) - Q(s,a))
    Q[s, a] = Q[s, a] + alpha * (r + gamma * np.max(Q[sprime, :]) - Q[s, a])
    return Q


def epsilon_greedy(Q, s, epsilone):
    """
    This function implements the epsilon greedy algorithm.
    Takes as unput the Q function for all states, a state s, and epsilon.
    It should return the action to take following the epsilon greedy algorithm.
    """
    if np.random.uniform(0, 1) < epsilone:
        # Explore: choose a random action
        return np.random.randint(0, Q.shape[1])
    else:
        # Exploit: choose the best action based on Q-table
        return np.argmax(Q[s, :])


if __name__ == "__main__":
    env = gym.make("Taxi-v3", render_mode="human")

    env.reset()
    env.render()

    Q = np.zeros([env.observation_space.n, env.action_space.n])

    alpha = 0.01 # choose your own

    gamma = 0.8 # choose your own

    epsilon = 0.2 # choose your own

    n_epochs = 20 # choose your own
    max_itr_per_epoch = 100 # choose your own
    rewards = []

    for e in range(n_epochs):
        r = 0

        S, _ = env.reset()

        for _ in range(max_itr_per_epoch):
            A = epsilon_greedy(Q=Q, s=S, epsilone=epsilon)

            Sprime, R, done, _, info = env.step(A)

            r += R

            Q = update_q_table(
                Q=Q, s=S, a=A, r=R, sprime=Sprime, alpha=alpha, gamma=gamma
            )

            # Update state and put a stoping criteria
            S = Sprime
            
            if done:
                break

        print("episode #", e, " : r = ", r)

        rewards.append(r)

    print("Average reward = ", np.mean(rewards))

    # plot the rewards in function of epochs
    plt.figure(figsize=(10, 6))
    plt.plot(rewards)
    plt.xlabel('Episode')
    plt.ylabel('Total Reward')
    plt.title('Reward per Episode during Q-Learning Training')
    plt.grid(True)
    plt.show()

    print("Training finished.\n")

    
    """
    
    Evaluate the q-learning algorihtm
    
    """
    
    # Evaluate the trained agent
    n_eval_episodes = 10
    eval_rewards = []
    
    print("Evaluating the trained agent...")
    for episode in range(n_eval_episodes):
        S, _ = env.reset()
        total_reward = 0
        done = False
        steps = 0
        
        while not done and steps < max_itr_per_epoch:
            # Use greedy policy (no exploration)
            A = np.argmax(Q[S, :])
            S, R, done, _, _ = env.step(A)
            total_reward += R
            steps += 1
        
        eval_rewards.append(total_reward)
        print(f"Evaluation episode {episode + 1}: Total reward = {total_reward}, Steps = {steps}")
    
    print(f"\nAverage evaluation reward over {n_eval_episodes} episodes: {np.mean(eval_rewards):.2f}")
    print(f"Standard deviation: {np.std(eval_rewards):.2f}")

    env.close()