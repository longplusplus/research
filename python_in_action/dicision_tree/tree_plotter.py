import matplotlib.pyplot as plt

decision_node = dict(boxstyle="sawtooth", fc="0.8")
leaf_node = dict(boxstyle="round4", fc="0.8")
arrow_args = dict(arrowstyle="<-")

def plot_node(node_text, center_point, parent_point, node_type):
    create_plot.ax1.annotate(node_text,
            xy=parent_point,
            xycoords='axes fraction',
            xytext=center_point,
            textcoords='axes fraction',
            va="center",
            ha="center",
            bbox=node_type,
            arrowprops=arrow_args)
    print create_plot.haha


def create_plot():
    fig = plt.figure(1, facecolor='white')
    fig.clf()
    create_plot.ax1 = plt.subplot(111, frameon=False)
    create_plot.haha = "hehe"
    plot_node('a decision node', (0.5, 0.1), (0.1, 0.5), decision_node)
    plot_node('a leaf node', (0.8, 0.1), (0.3, 0.8), leaf_node)
    plt.show()


