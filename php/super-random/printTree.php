<?php

class Node {
    public function __construct(string $data = 'd', ?Node $left = null, ?Node $right = null)
    {
        $this->data = $data;
        $this->left = $left;
        $this->right = $right;
    }

    public function left(): ?Node
    {
        return $this->left;
    }

    public function right(): ?Node
    {
        return $this->right;
    }

    public function data(): string
    {
        return $this->data;
    }
}

class Tree {
    public function __construct(Node $node)
    {
        $this->nodeList = $node;
        $this->ptr = $node;
    }

    public function printTree(?Node $node = null): void 
    {
       if ($node === null) {
           $this->printTree($this->ptr);
           return;
       }

       echo $node->data() ."\n";
       if ($node->left() !== null) $this->printTree($node->left());
       if ($node->right() !== null) $this->printTree($node->right());
    }

    public function addNode(Node $node, ?Node &$ptr = null): void
    {
        if ($ptr === null) {
            $this->addNode($node, $this->ptr);
            return;
        }

        if ($node->data() > $ptr->data() && $ptr->right() !== null  && ($ptr->right())->data() < $node->data()) {
            $r = $ptr->right();
            $this->addNode($node, $r);
            return;
        }

        if ($node->data() < $ptr->data() && $ptr->left() !== null && ($ptr->left())->data() > $node->data()) {
            $l = $ptr->left();
            $this->addNode($node, $l);
            return;
        }

        if ($node->data() > $ptr->data() && $ptr->right() !== null && $ptr->data() && $ptr->right()->data() > $node->data()) {
            $node->right = $ptr->right();
            $ptr->right = $node;
            return;
        }

        if ($node->data() < $ptr->data() && $ptr->left() !== null && $ptr->data() && $ptr->left()->data() < $node->data()) {
            $node->left = $ptr->left();
            $ptr->left = $node;
            return;
        }

        if ($node->data() > $ptr->data() && $ptr->right() === null) {
            $ptr->right = $node;
            return;
        }

        if ($node->data() < $ptr->data() && $ptr->left() === null) {
            $ptr->left = $node;
            return;
        }
    }
  
    public function resetPtr(): void
    {
        $this->ptr = $this->nodeList;
    }
}

$node = new Node('g');
$tree = new Tree($node);
$tree->addNode(new Node('c'));
$tree->addNode(new Node('m'));
$tree->addNode(new Node('z'));
$tree->addNode(new Node('l'));
$tree->addNode(new Node('a'));
$tree->resetPtr();
$tree->printTree();
