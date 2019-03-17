from math import log
import operator

def calc_shannon_ent(dateset):
    num_entries = len(dateset)
    label_counts = {}
    for feature in dateset:
        current_label = feature[-1]
        if current_label not in label_counts:
            label_counts[current_label] = 0;
        label_counts[current_label] += 1

    shannon_entropy = 0.0
    for key in label_counts:
        prob = float(label_counts[key]) / num_entries;
        shannon_entropy -= prob * log(prob, 2)

    return shannon_entropy


def create_dataset():
    dataset = [
        [1,1,'yes'],
        [1,1,'yes'],
        [1,0,'no'],
        [0,1,'no'],
        [0,1,'no']
    ]

    labels = ['no surfacing', 'flippers']
    return dataset, labels


def split_dataset(dataset, axis, value):
    ret_dataset = []
    for feature in dataset:
        if feature[axis] == value:
            reduced_feature = feature[:axis]
            reduced_feature.extend(feature[axis+1:])
            ret_dataset.append(reduced_feature)

    return ret_dataset


def choose_best_feature_to_split(dataset):
    num_features = len(dataset[0]) - 1
    base_entropy = calc_shannon_ent(dataset)
    best_info_gain = 0.0
    best_feature = -1
    for i in range(num_features):
        fealist = [example[i] for example in dataset]
        unique_vals = set(fealist)
        new_entropy = 0.0
        for value in unique_vals:
            sub_dataset = split_dataset(dataset, i, value)
            prob = len(sub_dataset) / float(len(dataset))
            new_entropy += calc_shannon_ent(sub_dataset)

        info_gain = base_entropy - new_entropy
        if info_gain > best_info_gain:
            best_info_gain = info_gain
            best_feature = i

        return best_feature


def majority_cnt(classlist):
    class_count = {}
    for vote in classlist:
        if vote not in class_count:
            class_count[vote] = 0
        class_count[vote] += 1

    sorted_kv = sorted(class_count.iteritems(),
            key = operator.itemgetter(1), reverse = True)
    return sorted_kv[0][0]


def create_tree(dataset, labels):
    class_list = [example[-1] for example in dataset]
    if class_list.count(class_list[0]) == len(class_list):
        return class_list[0]

    if len(dataset[0]) == 1:
        return majority_cnt(class_list)

    best_feature = choose_best_feature_to_split(dataset)
    print labels, best_feature
    best_feature_label = labels[best_feature]
    my_tree = {best_feature_label : {}}
    del(labels[best_feature])
    feature_values = [example[best_feature] for example in dataset]
    unique_values = set(feature_values)
    for value in unique_values:
        sub_labels = labels[:]
        my_tree[best_feature_label][value] = create_tree(split_dataset(dataset, best_feature, value), sub_labels)

    return my_tree
